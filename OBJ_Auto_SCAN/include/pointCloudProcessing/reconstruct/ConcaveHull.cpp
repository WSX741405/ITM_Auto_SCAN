#include "ConcaveHull.h"

ConcaveHull::ConcaveHull()
{
	_cloud.reset(new pcl::PointCloud<PointT>());
	_alpha = 0.01;
}

void ConcaveHull::Processing(pcl::PointCloud<PointT>::Ptr cloud)
{
	// Create a concave Hull representation of the projected inliers
	pcl::ConcaveHull<PointT> chull;
	chull.setInputCloud(cloud);
	chull.setAlpha(_alpha);
	chull.reconstruct(*_cloud);
	for (int counter = 0; counter < _cloud->size(); counter++)
	{
		_cloud->points[counter].r = 255;
		_cloud->points[counter].g = 255;
		_cloud->points[counter].b = 255;
	}
}

pcl::PolygonMeshPtr ConcaveHull::GetMesh()
{
	return NULL;
}

pcl::PointCloud<PointT>::Ptr ConcaveHull::GetCloud()
{
	return _cloud;
}

void ConcaveHull::SetSearchRadius(double searchRadius)
{
	return;
}

void ConcaveHull::SetMu(double mu)
{
	return;
}

void ConcaveHull::SetMaxNearestNeighbors(int maxNearestNeighbors)
{
	return;
}

void ConcaveHull::SetMaxSurfaceAngle(double maxSurfaceAngle)
{
	return;
}

void ConcaveHull::SetMinAngle(double minAngle)
{
	return;
}

void ConcaveHull::SetMaxAngle(double maxAngle)
{
	return;
}

void ConcaveHull::SetGridResolution(int gridResolutionX, int gridResolutionY, int gridResolutionZ)
{
	return;
}

void ConcaveHull::SetIsoLevel(float isoLevel)
{
	return;
}

void ConcaveHull::SetNormalSearchRadius(double normalSearchRadius)
{
	return;
}

void ConcaveHull::SetReconstructDepth(int depth)
{
	return;
}

void ConcaveHull::SetReconstructAlpha(double alpha)
{
	_alpha = alpha;
}