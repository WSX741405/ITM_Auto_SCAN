#include "OutlierRemovalFilter.h"

OutlierRemovalFilter::OutlierRemovalFilter()
{
	_filteredCloud.reset(new pcl::PointCloud<PointT>());

	_meanK = 50;
	_stddevMulThresh = 1.0;
}

void OutlierRemovalFilter::Processing(pcl::PointCloud<PointT>::Ptr cloud)
{
	pcl::StatisticalOutlierRemoval<PointT> sor;
	sor.setInputCloud(cloud);
	sor.setMeanK(50);
	sor.setStddevMulThresh(1.0);
	sor.filter(*_filteredCloud);
}

pcl::PointCloud<PointT>::Ptr OutlierRemovalFilter::GetResult()
{
	return _filteredCloud;
}

void OutlierRemovalFilter::SetLeafSize(float x, float y, float z)
{
	return;
}

void OutlierRemovalFilter::SetBoundingBox(float minX, float maxX, float minY, float maxY, float minZ, float maxZ)
{
	return;
}

void OutlierRemovalFilter::SetMeanK(int meanK)
{
	_meanK = meanK;
}

void OutlierRemovalFilter::SetStddevMulThresh(float stddevMulThresh)
{
	_stddevMulThresh = stddevMulThresh;
}