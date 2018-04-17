#include "GreedyProjection.h"

GreedyProjection::GreedyProjection()
{
	_surface.reset(new pcl::PolygonMesh());
	_searchRadius = 0.025;
	_mu = 2.5;
	_maxNearestNeighbors = 100;
	_maxSurfaceAngle = M_PI / 4;
	_minAngle = M_PI / 18;
	_maxAngle = 2 * M_PI / 3;
	_normalConsistency = false;
	_normalSearchRadius = 0.01;
}

void GreedyProjection::Processing(pcl::PointCloud<PointT>::Ptr cloud)
{
	boost::shared_ptr<pcl::PCLSurfaceBase<SurfacePointT> > surfaceReconstruction;
	pcl::GreedyProjectionTriangulation<SurfacePointT>* gp3 = new pcl::GreedyProjectionTriangulation<SurfacePointT>;
	gp3->setSearchRadius(_searchRadius);
	gp3->setMu(_mu);
	gp3->setMaximumNearestNeighbors(_maxNearestNeighbors);
	gp3->setMaximumSurfaceAngle(_maxSurfaceAngle); // 45 degrees
	gp3->setMinimumAngle(_minAngle); // 10 degrees
	gp3->setMaximumAngle(_maxAngle); // 120 degrees
	gp3->setNormalConsistency(_normalConsistency);
	surfaceReconstruction.reset(gp3);

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

pcl::PolygonMeshPtr GreedyProjection::GetResult()
{
	return _surface;
}

void GreedyProjection::SetSearchRadius(double searchRadius)
{
	_searchRadius = searchRadius;
}

void GreedyProjection::SetMu(double mu)
{
	_mu = mu;
}

void GreedyProjection::SetMaxNearestNeighbors(int maxNearestNeighbors)
{
	_maxNearestNeighbors = maxNearestNeighbors;
}

void GreedyProjection::SetMaxSurfaceAngle(double maxSurfaceAngle)
{
	_maxSurfaceAngle = maxSurfaceAngle * M_PI / 180;
}

void GreedyProjection::SetMinAngle(double minAngle)
{
	_minAngle = minAngle * M_PI / 180;
}

void GreedyProjection::SetMaxAngle(double maxAngle)
{
	_maxAngle = maxAngle * M_PI / 180;
}

void GreedyProjection::SetGridResolution(int gridResolutionX, int gridResolutionY, int gridResolutionZ)
{
	return;
}

void GreedyProjection::SetIsoLevel(float isoLevel)
{
	return;
}

void GreedyProjection::SetNormalSearchRadius(double normalSearchRadius)
{
	_normalSearchRadius = normalSearchRadius;
}

void GreedyProjection::SetReconstructDepth(int depth)
{
	return;
}