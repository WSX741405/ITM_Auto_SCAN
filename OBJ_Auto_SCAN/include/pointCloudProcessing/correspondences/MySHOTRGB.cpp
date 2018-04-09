#include "MySHOTRGB.h"

MySHOTRGB::MySHOTRGB()
{
	_correspondencesResult.reset(new pcl::Correspondences());
	_transformedSource.reset(new pcl::PointCloud<PointT>);
	//	default
	_descriptorRadiusSearch = 0.04;
	_normalRadiusSearch = 0.01;
	_correspondencesK = 1;
	_rejectorInlierThreshold = 1.0;
}

void MySHOTRGB::Processing(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<KeypointT>::Ptr sourceKpts, pcl::PointCloud<PointT>::Ptr target, pcl::PointCloud<KeypointT>::Ptr targetKpts)
{
	pcl::PointCloud<pcl::SHOT1344>::Ptr sourceDescriptor = ProessingDescriptor(source, sourceKpts);
	pcl::PointCloud<pcl::SHOT1344>::Ptr targetDescriptor = ProessingDescriptor(target, targetKpts);
	std::vector<int> source2Target = ProcessingCorrespondences(sourceDescriptor, targetDescriptor);
	std::vector<int> target2Source = ProcessingCorrespondences(targetDescriptor, sourceDescriptor);
	pcl::CorrespondencesPtr correspondences = ProcessingFilterCorrespondences(sourceKpts, targetKpts, source2Target, target2Source);
	DetermineInitialTransformation(source, sourceKpts, targetKpts, correspondences);
}

pcl::PointCloud<pcl::SHOT1344>::Ptr MySHOTRGB::ProessingDescriptor(pcl::PointCloud<PointT>::Ptr cloud, pcl::PointCloud<KeypointT>::Ptr keypoints)
{
	pcl::Feature<PointT, pcl::SHOT1344>::Ptr featureExtractor;
	pcl::PointCloud<pcl::SHOT1344>::Ptr descriptor;
	descriptor.reset(new pcl::PointCloud<pcl::SHOT1344>());

	featureExtractor.reset(new pcl::SHOTColorEstimation<PointT, pcl::Normal, pcl::SHOT1344>());
	featureExtractor->setSearchMethod(pcl::search::Search<PointT>::Ptr(new pcl::search::KdTree<PointT>));
	featureExtractor->setRadiusSearch(_descriptorRadiusSearch);
	pcl::PointCloud<PointT>::Ptr kpts(new pcl::PointCloud<PointT>);
	kpts->points.resize(keypoints->points.size());
	pcl::copyPointCloud(*keypoints, *kpts);
	pcl::FeatureFromNormals<PointT, pcl::Normal, pcl::SHOT1344>::Ptr featureFromNormals = boost::dynamic_pointer_cast<pcl::FeatureFromNormals<PointT, pcl::Normal, pcl::SHOT1344> > (featureExtractor);
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
		if (!pcl_isfinite(descriptor->at(i).descriptor[0])) //skipping NaNs
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

std::vector<int> MySHOTRGB::ProcessingCorrespondences(pcl::PointCloud<pcl::SHOT1344>::Ptr source, pcl::PointCloud<pcl::SHOT1344>::Ptr target)
{
	std::vector<int> correspondences;
	correspondences.resize(source->size());
	// Use a KdTree to search for the nearest matches in feature space
	pcl::KdTreeFLANN<pcl::SHOT1344> descriptorKdtree;
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

pcl::CorrespondencesPtr MySHOTRGB::ProcessingFilterCorrespondences(pcl::PointCloud<KeypointT>::Ptr sourceKpts, pcl::PointCloud<KeypointT>::Ptr targetKpts, std::vector<int> source2Target, std::vector<int> target2Source)
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

void MySHOTRGB::DetermineInitialTransformation(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<KeypointT>::Ptr sourceKpts, pcl::PointCloud<KeypointT>::Ptr targetKpts, pcl::CorrespondencesPtr correspondences)
{
	Eigen::Matrix4f initialTransformationMatrix;
	pcl::registration::TransformationEstimation<KeypointT, KeypointT>::Ptr transformationEstimation(new pcl::registration::TransformationEstimationSVD<KeypointT, KeypointT>);
	transformationEstimation->estimateRigidTransformation(*sourceKpts, *targetKpts, *correspondences, initialTransformationMatrix);

	pcl::transformPointCloud(*source, *_transformedSource, initialTransformationMatrix);
}

void MySHOTRGB::SetDescriptorRadius(float descriptorRadiusSearch)
{
	_descriptorRadiusSearch = descriptorRadiusSearch;
}

void MySHOTRGB::SetDescriptorKSearch(int kSearch)
{
	return;
}

void MySHOTRGB::SetNormalRadius(float normalRadiusSearch)
{
	_normalRadiusSearch = normalRadiusSearch;
}

void MySHOTRGB::SetCorrespondencesK(float correspondencesK)
{
	_correspondencesK = correspondencesK;
}

void MySHOTRGB::SetRejectorInlierThreshold(float rejectorInlierThreshold)
{
	_rejectorInlierThreshold = rejectorInlierThreshold;
}

pcl::CorrespondencesPtr MySHOTRGB::GetCorrespondencesResult()
{
	return _correspondencesResult;
}

pcl::PointCloud<PointT>::Ptr MySHOTRGB::GetResult()
{
	return _transformedSource;
}