#ifndef VoxelGrid_Filter
#define VoxelGrid_Filter

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include "FilterProcessing.h"

typedef pcl::PointXYZRGBA PointT;

class VoxelGridFilter : public FilterProcessing
{
public:
	VoxelGridFilter();
	void Processing(pcl::PointCloud<PointT>::Ptr cloud);
	void SetLeafSize(float x, float y, float z);
	pcl::PointCloud<PointT>::Ptr GetResult();

private:
	pcl::VoxelGrid<PointT> _voxelGrid;
	pcl::PointCloud<PointT>::Ptr _filteredCloud;

	float _x;
	float _y;
	float _z;
};

#endif