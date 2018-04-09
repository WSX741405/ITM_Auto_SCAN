#include "MarchingCubes.h"

MarchingCubes::MarchingCubes()
{
	_isoLevel = 0.001f;
	_gridResolutionX = 50;
	_gridResolutionY = 50;
	_gridResolutionZ = 50;
}

void MarchingCubes::Processing(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<PointT>::Ptr target)
{
	boost::shared_ptr<pcl::PCLSurfaceBase<SurfacePointT> > surfaceReconstruction;
	pcl::MarchingCubes<SurfacePointT>* mc = new pcl::MarchingCubesHoppe<SurfacePointT>;
	mc->setIsoLevel(_isoLevel);
	mc->setGridResolution(_gridResolutionX, _gridResolutionY, _gridResolutionZ);
	surfaceReconstruction.reset(mc);

	pcl::PointCloud<PointT>::Ptr merged(new pcl::PointCloud<PointT>);
	*merged = *source;
	*merged += *target;

	pcl::PointCloud<SurfacePointT>::Ptr vertices(new pcl::PointCloud<SurfacePointT>);
	pcl::copyPointCloud(*merged, *vertices);

	pcl::NormalEstimation<PointT, SurfacePointT> normalEstimation;
	normalEstimation.setSearchMethod(pcl::search::Search<PointT>::Ptr(new pcl::search::KdTree<PointT>));
	normalEstimation.setRadiusSearch(0.01);
	normalEstimation.setInputCloud(merged);
	normalEstimation.compute(*vertices);

	pcl::search::KdTree<SurfacePointT>::Ptr tree(new pcl::search::KdTree<SurfacePointT>);
	tree->setInputCloud(vertices);

	surfaceReconstruction->setSearchMethod(tree);
	surfaceReconstruction->setInputCloud(vertices);
	surfaceReconstruction->reconstruct(_surface);
}

pcl::PolygonMesh MarchingCubes::GetSurface()
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