#ifndef OUTLIER_REMOVAL
#define OUTLIER_REMOVAL

#include "Typedef.h"
#include <pcl/filters/statistical_outlier_removal.h>

#include "FilterProcessing.h"

class OutlierRemovalFilter : public FilterProcessing
{
public:
	OutlierRemovalFilter();
	void Processing(pcl::PointCloud<PointT>::Ptr cloud);
	pcl::PointCloud<PointT>::Ptr GetResult();
	void SetLeafSize(float x, float y, float z);
	void SetBoundingBox(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
	void SetMeanK(int meanK);
	void SetStddevMulThresh(float stddevMulThresh);

private:
	pcl::PointCloud<PointT>::Ptr _filteredCloud;

	int _meanK;
	float _stddevMulThresh;
};

#endif