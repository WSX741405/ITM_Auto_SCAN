#include "BoundingBoxFilter.h"

BoundingBoxFilter::BoundingBoxFilter()
{
	_filteredCloud.reset(new pcl::PointCloud<PointT>());

	//	default
	_minX = -1;
	_maxX = 1;
	_minY = -1;
	_maxY = 1;
	_minZ = -1;
	_maxZ = 1;
}

void BoundingBoxFilter::Processing(pcl::PointCloud<PointT>::Ptr cloud)
{
	_boxFilter.setMin(Eigen::Vector4f(_minX, _minY, _minZ, 1.0));
	_boxFilter.setMax(Eigen::Vector4f(_maxX, _maxY, _maxZ, 1.0));
	_boxFilter.setInputCloud(cloud);
	_boxFilter.filter(*_filteredCloud);
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

void BoundingBoxFilter::SetMeanK(int meanK)
{
	return;
}

void BoundingBoxFilter::SetStddevMulThresh(float stddevMulThresh)
{
	return;
}