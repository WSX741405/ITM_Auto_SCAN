#include "MyPFHRGB.h"

MyPFHRGB::MyPFHRGB()
{
	_correspondencesResult.reset(new pcl::Correspondences());
	_transformedSource.reset(new pcl::PointCloud<PointT>);
	//	default
	_kSearch = 50;
	_normalRadiusSearch = 0.01;
	_correspondencesK = 1;
	_rejectorInlierThreshold = 1.0;
}

void MyPFHRGB::Processing(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<KeypointT>::Ptr sourceKpts, pcl::PointCloud<PointT>::Ptr target, pcl::PointCloud<KeypointT>::Ptr targetKpts)
{
	pcl::PointCloud<pcl::PFHRGBSignature250>::Ptr sourceDescriptor = ProessingDescriptor(source, sourceKpts);
	pcl::PointCloud<pcl::PFHRGBSignature250>::Ptr targetDescriptor = ProessingDescriptor(target, targetKpts);
	std::vector<int> source2Target = ProcessingCorrespondences(sourceDescriptor, targetDescriptor);
	std::vector<int> target2Source = ProcessingCorrespondences(targetDescriptor, sourceDescriptor);
	pcl::CorrespondencesPtr correspondences = ProcessingFilterCorrespondences(sourceKpts, targetKpts, source2Target, target2Source);
	DetermineInitialTransformation(source, sourceKpts, targetKpts, correspondences);
}

pcl::PointCloud<pcl::PFHRGBSignature250>::Ptr MyPFHRGB::ProessingDescriptor(pcl::PointCloud<PointT>::Ptr cloud, pcl::PointCloud<KeypointT>::Ptr keypoints)
{
	pcl::Feature<PointT, pcl::PFHRGBSignature250>::Ptr featureExtractor;
	pcl::PointCloud<pcl::PFHRGBSignature250>::Ptr descriptor;
	descriptor.reset(new pcl::PointCloud<pcl::PFHRGBSignature250>());

	featureExtractor.reset(new pcl::PFHRGBEstimation<PointT, pcl::Normal, pcl::PFHRGBSignature250>());
	featureExtractor->setSearchMethod(pcl::search::Search<PointT>::Ptr(new pcl::search::KdTree<PointT>));
	featureExtractor->setKSearch(50);
	pcl::PointCloud<PointT>::Ptr kpts(new pcl::PointCloud<PointT>);
	kpts->points.resize(keypoints->points.size());
	pcl::copyPointCloud(*keypoints, *kpts);
	pcl::FeatureFromNormals<PointT, pcl::Normal, pcl::PFHRGBSignature250>::Ptr featureFromNormals = boost::dynamic_pointer_cast<pcl::FeatureFromNormals<PointT, pcl::Normal, pcl::PFHRGBSignature250> > (featureExtractor);
	featureExtractor->setSearchSurface(cloud);
	featureExtractor->setInputCloud(kpts);
	if (featureFromNormals)
	{
		pcl::PointCloud<pcl::Normal>::Ptr normals(new  pcl::PointCloud<pcl::Normal>);
		pcl::NormalEstimation<PointT, pcl::Normal> normalEstimation;
		normalEstimation.setSearchMethod(pcl::search::Search<PointT>::Ptr(new pcl::search::KdTree<PointT>));
		normalEstimation.setRadiusSearch(_normalRadiusSearch);
		normalEstimation.setInputCloud(cloud);
		normalEstimation.compute(*normals);
		featureFromNormals->setInputNormals(normals);
	}
	featureExtractor->compute(*descriptor);
	for (int j = 0, i = static_cast<int> (descriptor->size()) - 1; i >= 0; --i)
	{
		if (!pcl_isfinite(descriptor->at(i).histogram[0])) //skipping NaNs
		{
			descriptor->erase(descriptor->begin() + i);
			keypoints->erase(keypoints->begin() + i);
			j++;
			//cout << "erase" << std::flush;
			continue;
		}
	}

	return descriptor;
}

std::vector<int> MyPFHRGB::ProcessingCorrespondences(pcl::PointCloud<pcl::PFHRGBSignature250>::Ptr source, pcl::PointCloud<pcl::PFHRGBSignature250>::Ptr target)
{
	std::vector<int> correspondences;
	correspondences.resize(source->size());
	// Use a KdTree to search for the nearest matches in feature space
	pcl::KdTreeFLANN<pcl::PFHRGBSignature250> descriptorKdtree;
	descriptorKdtree.setInputCloud(target);
	// Find the index of the best match for each keypoint, and store it in "correspondences_out"
	std::vector<int> kIndices(_correspondencesK);
	std::vector<float> kSquaredDistances(_correspondencesK);
	for (int i = 0; i < static_cast<int> (source->size()); ++i)
	{
		descriptorKdtree.nearestKSearch(*source, i, _correspondencesK, kIndices, kSquaredDistances);
		correspondences[i] = kIndices[0];
	}
	return correspondences;
}

pcl::CorrespondencesPtr MyPFHRGB::ProcessingFilterCorrespondences(pcl::PointCloud<KeypointT>::Ptr sourceKpts, pcl::PointCloud<KeypointT>::Ptr targetKpts, std::vector<int> source2Target, std::vector<int> target2Source)
{
	std::vector<std::pair<unsigned, unsigned> > correspondences;
	for (unsigned cIdx = 0; cIdx < source2Target.size(); ++cIdx)
		if (target2Source[source2Target[cIdx]] == static_cast<int> (cIdx))
			correspondences.push_back(std::make_pair(cIdx, source2Target[cIdx]));

	_correspondencesResult->resize(correspondences.size());
	for (unsigned cIdx = 0; cIdx < correspondences.size(); ++cIdx)
	{
		(*_correspondencesResult)[cIdx].index_query = correspondences[cIdx].first;
		(*_correspondencesResult)[cIdx].index_match = correspondences[cIdx].second;
	}

	pcl::registration::CorrespondenceRejectorSampleConsensus<KeypointT> rejector;
	rejector.setInputSource(sourceKpts);
	rejector.setInputTarget(targetKpts);
	rejector.setInputCorrespondences(_correspondencesResult);
	rejector.setInlierThreshold(_rejectorInlierThreshold);
	rejector.getCorrespondences(*_correspondencesResult);
	return _correspondencesResult;
}

void MyPFHRGB::DetermineInitialTransformation(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<KeypointT>::Ptr sourceKpts, pcl::PointCloud<KeypointT>::Ptr targetKpts, pcl::CorrespondencesPtr correspondences)
{
	Eigen::Matrix4f initialTransformationMatrix;
	pcl::registration::TransformationEstimation<KeypointT, KeypointT>::Ptr transformationEstimation(new pcl::registration::TransformationEstimationSVD<KeypointT, KeypointT>);
	transformationEstimation->estimateRigidTransformation(*sourceKpts, *targetKpts, *correspondences, initialTransformationMatrix);

	pcl::transformPointCloud(*source, *_transformedSource, initialTransformationMatrix);
}

void MyPFHRGB::SetDescriptorRadius(float descriptorRadiusSearch)
{
	return;
}

void MyPFHRGB::SetNormalRadius(float normalRadiusSearch)
{
	_normalRadiusSearch = normalRadiusSearch;
}

void MyPFHRGB::SetCorrespondencesK(float correspondencesK)
{
	_correspondencesK = correspondencesK;
}

void MyPFHRGB::SetDescriptorKSearch(int kSearch)
{
	_kSearch = kSearch;
}

void MyPFHRGB::SetRejectorInlierThreshold(float rejectorInlierThreshold)
{
	_rejectorInlierThreshold = rejectorInlierThreshold;
}

pcl::CorrespondencesPtr MyPFHRGB::GetCorrespondencesResult()
{
	return _correspondencesResult;
}

pcl::PointCloud<PointT>::Ptr MyPFHRGB::GetResult()
{
	return _transformedSource;
}