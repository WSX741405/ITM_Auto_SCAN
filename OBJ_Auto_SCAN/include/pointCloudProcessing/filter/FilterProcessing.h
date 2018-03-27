#ifndef FILTER_PROCESSING
#define FILTER_PROCESSING

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

typedef pcl::PointXYZRGBA PointT;

class FilterProcessing
{
public:
	virtual void Processing(pcl::PointCloud<PointT>::Ptr cloud) = 0;
	virtual pcl::PointCloud<PointT>::Ptr GetResult() = 0;
	virtual void SetLeafSize(float x, float y, float z) = 0;
private:

};

#endif