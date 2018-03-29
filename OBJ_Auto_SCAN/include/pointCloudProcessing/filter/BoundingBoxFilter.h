#ifndef BOUNDING_BOX_FILTER
#define BOUNDING_BOX_FILTER

#include "FilterProcessing.h"

class BoundingBoxFilter : public FilterProcessing
{
public:
	BoundingBoxFilter();
	void Processing(pcl::PointCloud<PointT>::Ptr cloud);
	pcl::PointCloud<PointT>::Ptr GetResult();
	void SetLeafSize(float x, float y, float z);
	void SetBoundingBox(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);

private:
	pcl::PointCloud<PointT>::Ptr _filteredCloud;
	float _minX;
	float _maxX;
	float _minY;
	float _maxY;
	float _minZ;
	float _maxZ;
};

#endif