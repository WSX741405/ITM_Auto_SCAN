#include "MarchingCubes.h"

MarchingCubes::MarchingCubes()
{
	_surface.reset(new pcl::PolygonMesh());
	_isoLevel = 0.001f;
	_gridResolutionX = 50;
	_gridResolutionY = 50;
	_gridResolutionZ = 50;
	_normalSearchRadius = 0.01;
}

void MarchingCubes::Processing(pcl::PointCloud<PointT>::Ptr cloud)
{
	boost::shared_ptr<pcl::PCLSurfaceBase<SurfacePointT> > surfaceReconstruction;
	pcl::MarchingCubes<SurfacePointT>* mc = new pcl::MarchingCubesHoppe<SurfacePointT>;
	mc->setIsoLevel(_isoLevel);
	mc->setGridResolution(_gridResolutionX, _gridResolutionY, _gridResolutionZ);
	surfaceReconstruction.reset(mc);

	pcl::PointCloud<SurfacePointT>::Ptr vertices(new pcl::PointCloud<SurfacePointT>);
	pcl::copyPointCloud(*cloud, *vertices);

	pcl::NormalEstimation<PointT, SurfacePointT> normalEstimation;
	normalEstimation.setSearchMethod(pcl::search::Search<PointT>::Ptr(new pcl::search::KdTree<PointT>));
	normalEstimation.setRadiusSearch(_normalSearchRadius);
	normalEstimation.setInputCloud(cloud);
	normalEstimation.compute(*vertices);

	pcl::search::KdTree<SurfacePointT>::Ptr tree(new pcl::search::KdTree<SurfacePointT>);
	tree->setInputCloud(vertices);

	surfaceReconstruction->setSearchMethod(tree);
	surfaceReconstruction->setInputCloud(vertices);
	surfaceReconstruction->reconstruct(*_surface);
}

pcl::PolygonMeshPtr MarchingCubes::GetResult()
{
	return _surface;
}

void MarchingCubes::SetSearchRadius(double searchRadius)
{
	return;
}

void MarchingCubes::SetMu(double mu)
{
	return;
}

void MarchingCubes::SetMaxNearestNeighbors(int maxNearestNeighbors)
{
	return;
}

void MarchingCubes::SetMaxSurfaceAngle(double maxSurfaceAngle)
{
	return;
}

void MarchingCubes::SetMinAngle(double minAngle)
{
	return;
}

void MarchingCubes::SetMaxAngle(double maxAngle)
{
	return;
}

void MarchingCubes::SetGridResolution(int gridResolutionX, int gridResolutionY, int gridResolutionZ)
{
	_gridResolutionX = gridResolutionX;
	_gridResolutionY = gridResolutionY;
	_gridResolutionY = gridResolutionY;
}

void MarchingCubes::SetIsoLevel(float isoLevel)
{
	_isoLevel = isoLevel;
}

void MarchingCubes::SetNormalSearchRadius(double normalSearchRadius)
{
	_normalSearchRadius = normalSearchRadius;
}

void MarchingCubes::SetReconstructDepth(int depth)
{
	return;
}