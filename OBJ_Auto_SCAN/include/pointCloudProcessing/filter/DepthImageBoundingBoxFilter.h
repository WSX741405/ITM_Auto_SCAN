#ifndef DEPTH_IMAGE_BOUNDING_BOX_FILTER
#define DEPTH_IMAGE_BOUNDING_BOX_FILTER

#include "Typedef.h"
#include "FilterProcessing.h"

class DepthImageBoundingBoxFilter : public FilterProcessing
{
public:
	void Processing(pcl::PointCloud<PointT>::Ptr cloud);
	pcl::PointCloud<PointT>::Ptr GetResult();
	void SetLeafSize(float x, float y, float z);
	void SetBoundingBox(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
	void SetMeanK(int meanK);
	void SetStddevMulThresh(float stddevMulThresh);

private:
	pcl::PointCloud<PointT>::Ptr _filteredCloud;
	double _minX;
	double _maxX;
	double _minY;
	double _maxY;
	double _minZ;
	double _maxZ;
};

#endif