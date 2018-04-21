#ifndef REGESTRATION_PROCESSING
#define REGESTRATION_PROCESSING

#include "Typedef.h"

class RegestrationProcessing
{
public:
	virtual void Processing(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<PointT>::Ptr target) = 0;
	virtual void SetCorrespondenceDistance(float maxCorrespondenceDistance) = 0;
	virtual void SetRansacOutlierRejectionThreshold(float ransacOutlierRejectionThreshold) = 0;
	virtual void SetTransformationEpsilon(float transformationEpsilon) = 0;
	virtual void SetMaximumIterations(int maximumIterations) = 0;
	virtual pcl::PointCloud<PointT>::Ptr GetResult() = 0;
	virtual Eigen::Matrix4f GetMatrix() = 0;

private:

};


#endif