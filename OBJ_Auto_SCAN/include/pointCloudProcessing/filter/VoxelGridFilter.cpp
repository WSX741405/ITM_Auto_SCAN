#include "VoxelGridFilter.h"

VoxelGridFilter::VoxelGridFilter()
{
	_filteredCloud.reset(new pcl::PointCloud<PointT>());

	//	default
	_x = 0.01f;
	_y = 0.01f;
	_z = 0.01f;
}

void VoxelGridFilter::Processing(pcl::PointCloud<PointT>::Ptr cloud)
{
	_voxelGrid.setInputCloud(cloud);
	_voxelGrid.setLeafSize(_x, _y, _z);
	_voxelGrid.filter(*_filteredCloud);
}

void VoxelGridFilter::SetLeafSize(float x, float y, float z)
{
	_x = x;
	_y = y;
	_z = z;
}

pcl::PointCloud<PointT>::Ptr VoxelGridFilter::GetResult()
{
	return _filteredCloud;
}