#include "MyICP.h"

MyICP::MyICP()
{
	_maxCorrespondenceDistance = 0.05;
	_ransacOutlierRejectionThreshold = 0.05;
	_transformationEpsilon = 0.000001;
	_maximumIterations = 1000;
}

void MyICP::Processing(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<PointT>::Ptr target)
{
	pcl::Registration<PointT, PointT>::Ptr registration(new pcl::IterativeClosestPoint<PointT, PointT>);
	registration->setInputSource(source);
	//registration->setInputSource (source_segmented_);
	registration->setInputTarget(target);
	registration->setMaxCorrespondenceDistance(_maxCorrespondenceDistance);
	registration->setRANSACOutlierRejectionThreshold(_ransacOutlierRejectionThreshold);
	registration->setTransformationEpsilon(_transformationEpsilon);
	registration->setMaximumIterations(_maximumIterations);
	registration->align(*_registeredCloud);
	_registeredMatrix = registration->getFinalTransformation();
}

void MyICP::SetCorrespondenceDistance(float maxCorrespondenceDistance)
{
	_maxCorrespondenceDistance = maxCorrespondenceDistance;
}

void MyICP::SetRansacOutlierRejectionThreshold(float ransacOutlierRejectionThreshold)
{
	_ransacOutlierRejectionThreshold = ransacOutlierRejectionThreshold;
}

void MyICP::SetTransformationEpsilon(float transformationEpsilon)
{
	_transformationEpsilon = transformationEpsilon;
}

void MyICP::SetMaximumIterations(int maximumIterations)
{
	_maximumIterations = maximumIterations;
}