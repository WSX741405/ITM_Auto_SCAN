#ifndef CORRESPONDENCES_PROCESSING
#define CORRESPONDENCES_PROCESSING

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointXYZI KeypointT;

class CorrespondencesProcessing
{
public:
	virtual void Processing(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<KeypointT>::Ptr sourceKpts, pcl::PointCloud<PointT>::Ptr target, pcl::PointCloud<KeypointT>::Ptr targetKpts) = 0;
	virtual void SetDescriptorRadius(float descriptorRadiusSearch) = 0;
	virtual void SetNormalRadius(float normalRadiusSearch) = 0;
	virtual void SetCorrespondencesK(float correspondencesK) = 0;
private:

};

#endif