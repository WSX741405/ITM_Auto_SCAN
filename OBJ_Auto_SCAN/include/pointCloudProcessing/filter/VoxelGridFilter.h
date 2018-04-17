#ifndef VoxelGrid_Filter
#define VoxelGrid_Filter

#include "Typedef.h"
#include <pcl/filters/voxel_grid.h>
#include "FilterProcessing.h"

class VoxelGridFilter : public FilterProcessing
{
public:
	VoxelGridFilter();
	void Processing(pcl::PointCloud<PointT>::Ptr cloud);
	void SetLeafSize(float x, float y, float z);
	void SetBoundingBox(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
	void SetMeanK(int meanK);
	void SetStddevMulThresh(float stddevMulThresh);
	pcl::PointCloud<PointT>::Ptr GetResult();

private:
	pcl::VoxelGrid<PointT> _voxelGrid;
	pcl::PointCloud<PointT>::Ptr _filteredCloud;

	float _x;
	float _y;
	float _z;
};

#endif