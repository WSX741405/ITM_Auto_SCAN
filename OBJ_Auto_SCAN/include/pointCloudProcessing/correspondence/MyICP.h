#ifndef MY_ICP
#define MY_ICP

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>

typedef pcl::PointXYZRGBA PointT;

class MyICP
{
public:
	MyICP();
	void Processing(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<PointT>::Ptr target);
	void SetCorrespondenceDistance(float maxCorrespondenceDistance);
	void SetRansacOutlierRejectionThreshold(float ransacOutlierRejectionThreshold);
	void SetTransformationEpsilon(float transformationEpsilon);
	void SetMaximumIterations(int maximumIterations);

private:

	pcl::PointCloud<PointT>::Ptr _registeredCloud;
	Eigen::Matrix4f _registeredMatrix;

	float _maxCorrespondenceDistance;
	float _ransacOutlierRejectionThreshold;
	float _transformationEpsilon;
	int _maximumIterations;
};

#endif