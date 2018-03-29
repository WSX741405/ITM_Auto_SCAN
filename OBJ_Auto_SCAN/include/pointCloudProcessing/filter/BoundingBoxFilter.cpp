#include "BoundingBoxFilter.h"

BoundingBoxFilter::BoundingBoxFilter()
{
	_filteredCloud.reset(new pcl::PointCloud<PointT>());

	//	default
	_minX = 0.01f;
	_maxX = 0.09f;
	_minY = 0.01f;
	_maxY = 0.09f;
	_minZ = 0.01f;
	_maxZ = 0.09f;
}

void BoundingBoxFilter::Processing(pcl::PointCloud<PointT>::Ptr cloud)
{

}

pcl::PointCloud<PointT>::Ptr BoundingBoxFilter::GetResult()
{
	return _filteredCloud;
}

void BoundingBoxFilter::SetLeafSize(float x, float y, float z)
{
	return;
}

void BoundingBoxFilter::SetBoundingBox(float minX, float maxX, float minY, float maxY, float minZ, float maxZ)
{
	if (minX < maxX && minY < maxY && minZ < maxZ)
	{
		_minX = minX;
		_maxX = maxX;
		_minY = minY;
		_maxY = maxY;
		_minZ = minZ;
		_maxZ = maxZ;
	}
}