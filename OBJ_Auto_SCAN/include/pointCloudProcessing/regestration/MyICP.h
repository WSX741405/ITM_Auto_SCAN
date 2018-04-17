#ifndef MY_ICP
#define MY_ICP

#include "Typedef.h"
#include <pcl/registration/icp.h>

#include "RegestrationProcessing.h"

class MyICP : public RegestrationProcessing
{
public:
	MyICP();
	void Processing(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<PointT>::Ptr target);
	void SetCorrespondenceDistance(float maxCorrespondenceDistance);
	void SetRansacOutlierRejectionThreshold(float ransacOutlierRejectionThreshold);
	void SetTransformationEpsilon(float transformationEpsilon);
	void SetMaximumIterations(int maximumIterations);
	pcl::PointCloud<PointT>::Ptr GetResult();

private:

	pcl::PointCloud<PointT>::Ptr _registeredCloud;
	Eigen::Matrix4f _registeredMatrix;

	float _maxCorrespondenceDistance;
	float _ransacOutlierRejectionThreshold;
	float _transformationEpsilon;
	int _maximumIterations;
};

#endif