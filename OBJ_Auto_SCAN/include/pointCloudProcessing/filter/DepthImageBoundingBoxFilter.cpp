#include "DepthImageBoundingBoxFilter.h"

void DepthImageBoundingBoxFilter::Processing(pcl::PointCloud<PointT>::Ptr cloud)
{
	int width = _maxX - _minX;
	int height = _maxY - _minY;
	if (width == 1 || height == 1)
		return;		//pcl 2D execption
	//pcl::PointCloud<PointT>::Ptr cpyCloud;
	//cpyCloud.reset(new pcl::PointCloud<PointT>(width / 2, height / 2));
	_filteredCloud.reset(new pcl::PointCloud<PointT>(width, height));
	for (int widthIndex = std::ceil(_minX); widthIndex < std::floor(_maxX); widthIndex++)
	{
		for (int heightIndex = std::ceil(_minY); heightIndex < std::floor(_maxY); heightIndex++)
		{
			int filteredWidthIndex = widthIndex - std::ceil(_minX);
			int filteredHeightIndex = heightIndex - std::ceil(_minY);
			PointT point(cloud->at(widthIndex, heightIndex));
			if (point.z > _maxZ || point.z < _minZ)
			{
				_filteredCloud->at(filteredWidthIndex, filteredHeightIndex).x = -NAN;
				_filteredCloud->at(filteredWidthIndex, filteredHeightIndex).y = -NAN;
				_filteredCloud->at(filteredWidthIndex, filteredHeightIndex).z = -NAN;
				_filteredCloud->at(filteredWidthIndex, filteredHeightIndex).r = -NAN;
				_filteredCloud->at(filteredWidthIndex, filteredHeightIndex).g = -NAN;
				_filteredCloud->at(filteredWidthIndex, filteredHeightIndex).b = -NAN;
			}
			else
				_filteredCloud->at(filteredWidthIndex, filteredHeightIndex) = point;
		}
	}
}

pcl::PointCloud<PointT>::Ptr DepthImageBoundingBoxFilter::GetResult()
{
	return _filteredCloud;
}

void DepthImageBoundingBoxFilter::SetLeafSize(float x, float y, float z)
{
	return;
}

void DepthImageBoundingBoxFilter::SetBoundingBox(float minX, float maxX, float minY, float maxY, float minZ, float maxZ)
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

void DepthImageBoundingBoxFilter::SetMeanK(int meanK)
{
	return;
}

void DepthImageBoundingBoxFilter::SetStddevMulThresh(float stddevMulThresh)
{
	return;
}