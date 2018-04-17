#ifndef FILTER_PROCESSING
#define FILTER_PROCESSING

#include "Typedef.h"

class FilterProcessing
{
public:
	virtual void Processing(pcl::PointCloud<PointT>::Ptr cloud) = 0;
	virtual pcl::PointCloud<PointT>::Ptr GetResult() = 0;
	virtual void SetLeafSize(float x, float y, float z) = 0;
	virtual void SetBoundingBox(float minX, float maxX, float minY, float maxY, float minZ, float maxZ) = 0;
	virtual void SetMeanK(int meanK) = 0;
	virtual void SetStddevMulThresh(float stddevMulThresh) = 0;

private:

};

#endif