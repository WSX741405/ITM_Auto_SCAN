#include "MyPoisson.h"

MyPoisson::MyPoisson()
{
	_surface.reset(new pcl::PolygonMesh());
	_normalSearchRadius = 0.01;
	_depth = 9;
}

void MyPoisson::Processing(pcl::PointCloud<PointT>::Ptr cloud)
{
	pcl::PointCloud<SurfacePointT>::Ptr vertices(new pcl::PointCloud<SurfacePointT>);
	pcl::copyPointCloud(*cloud, *vertices);

	pcl::NormalEstimation<PointT, SurfacePointT> normalEstimation;
	normalEstimation.setSearchMethod(pcl::search::Search<PointT>::Ptr(new pcl::search::KdTree<PointT>));
	normalEstimation.setRadiusSearch(_normalSearchRadius);
	normalEstimation.setInputCloud(cloud);
	normalEstimation.compute(*vertices);

	pcl::Poisson<SurfacePointT> poisson;
	poisson.setDepth(_depth);
	poisson.setInputCloud(vertices);
	poisson.reconstruct(*_surface);
}

pcl::PolygonMeshPtr MyPoisson::GetSurface()
{
	return _surface;
}

void MyPoisson::SetSearchRadius(double searchRadius)
{
	return;
}

void MyPoisson::SetMu(double mu)
{
	return;
}

void MyPoisson::SetMaxNearestNeighbors(int maxNearestNeighbors)
{
	return;
}

void MyPoisson::SetMaxSurfaceAngle(double maxSurfaceAngle)
{
	return;
}

void MyPoisson::SetMinAngle(double minAngle)
{
	return;
}

void MyPoisson::SetMaxAngle(double maxAngle)
{
	return;
}

void MyPoisson::SetGridResolution(int gridResolutionX, int gridResolutionY, int gridResolutionZ)
{
	return;
}

void MyPoisson::SetIsoLevel(float isoLevel)
{
	return;
}

void MyPoisson::SetNormalSearchRadius(double normalSearchRadius)
{
	return;
}

void MyPoisson::SetReconstructDepth(int depth)
{
	_depth = depth;
}