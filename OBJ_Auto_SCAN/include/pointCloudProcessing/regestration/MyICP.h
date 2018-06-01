#ifndef MY_ICP
#define MY_ICP

#include "Typedef.h"
#include <pcl/filters/filter.h>
#include <pcl/registration/icp.h>

#include "RegestrationProcessing.h"

class MyICP : public RegestrationProcessing
{
public:
	MyICP();
	void Processing(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<PointT>::Ptr target);
	void SetCorrespondenceDistance(float maxCorrespondenceDistance);
	void SetRansacOutlierRejectionThreshold(float ransacOutlierRejectionThreshold);
	void SetEuclideanFitnessEpsilon(float euclideanFitnessEpsilon);
	void SetMaximumIterations(int maximumIterations);
	Eigen::Matrix4f GetMatrix();
	pcl::PointCloud<PointT>::Ptr GetResult();
	bool HasConverged();

private:

	pcl::PointCloud<PointT>::Ptr _registeredCloud;
	Eigen::Matrix4f _registeredMatrix;
	bool _hasConverged;

	float _maxCorrespondenceDistance;
	float _ransacOutlierRejectionThreshold;
	float _euclideanFitnessEpsilon;
	float _transformationEpsilon;
	int _maximumIterations;
};

#endif