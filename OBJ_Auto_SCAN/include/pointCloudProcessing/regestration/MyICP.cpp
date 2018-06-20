#include "MyICP.h"

MyICP::MyICP()
{
	_registeredCloud.reset(new pcl::PointCloud<PointT>());

	_maxCorrespondenceDistance = 0.05;
	_ransacOutlierRejectionThreshold = 0.05;
	_transformationEpsilon = 1e-12;
	_maximumIterations = 1000;
	_euclideanFitnessEpsilon = 1e-12;
}

void MyICP::Processing(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<PointT>::Ptr target)
{
	std::vector<int> mapSource;
	std::vector<int> mapTarget;
	pcl::removeNaNFromPointCloud(*source, *source, mapSource);
	pcl::removeNaNFromPointCloud(*target, *target, mapTarget);
	pcl::Registration<PointT, PointT>::Ptr registration(new pcl::IterativeClosestPoint<PointT, PointT>);
	registration->setInputSource(source);
	//registration->setInputSource (source_segmented_);
	registration->setInputTarget(target);
	registration->setMaxCorrespondenceDistance(_maxCorrespondenceDistance);
	registration->setRANSACOutlierRejectionThreshold(_ransacOutlierRejectionThreshold);
	registration->setTransformationEpsilon(_transformationEpsilon);
	registration->setEuclideanFitnessEpsilon(_euclideanFitnessEpsilon);
	registration->setMaximumIterations(_maximumIterations);
	registration->align(*_registeredCloud);
	_registeredMatrix = registration->getFinalTransformation();
	*_registeredCloud += *target;
	_hasConverged = registration->hasConverged();
}

void MyICP::SetCorrespondenceDistance(float maxCorrespondenceDistance)
{
	_maxCorrespondenceDistance = maxCorrespondenceDistance;
}

void MyICP::SetRansacOutlierRejectionThreshold(float ransacOutlierRejectionThreshold)
{
	_ransacOutlierRejectionThreshold = ransacOutlierRejectionThreshold;
}

void MyICP::SetEuclideanFitnessEpsilon(float euclideanFitnessEpsilon)
{
	_euclideanFitnessEpsilon = euclideanFitnessEpsilon;
}

void MyICP::SetMaximumIterations(int maximumIterations)
{
	_maximumIterations = maximumIterations;
}

Eigen::Matrix4f MyICP::GetMatrix()
{
	return _registeredMatrix;
}

pcl::PointCloud<PointT>::Ptr MyICP::GetResult()
{
	return _registeredCloud;
}

bool MyICP::HasConverged()
{
	return _hasConverged;
}