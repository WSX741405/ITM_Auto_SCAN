#include "MyPoisson.h"

MyPoisson::MyPoisson()
{
	_surface.reset(new pcl::PolygonMesh());
	_normalSearchRadius = 0.01;
	_depth = 9;
}

void MyPoisson::Processing(pcl::PointCloud<PointT>::Ptr cloud)
{
	/*
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
	poisson.reconstruct(*_surface);*/
	pcl::PointCloud<PointT>::Ptr filtered(new pcl::PointCloud<PointT>());
	pcl::PassThrough<PointT> filter;
	filter.setInputCloud(cloud);
	filter.filter(*filtered);
	
	pcl::NormalEstimation<PointT, NormalT> ne;
	//ne.setNumberOfThreads(8);
	ne.setInputCloud(filtered);
	ne.setRadiusSearch(_normalSearchRadius);
	Eigen::Vector4f centroid;
	compute3DCentroid(*filtered, centroid);
	ne.setViewPoint(centroid[0], centroid[1], centroid[2]);

	pcl::PointCloud<NormalT>::Ptr cloudNormals(new pcl::PointCloud<NormalT>());
	ne.compute(*cloudNormals);

	for (size_t i = 0; i < cloudNormals->size(); ++i) {
		cloudNormals->points[i].normal_x *= -1;
		cloudNormals->points[i].normal_y *= -1;
		cloudNormals->points[i].normal_z *= -1;
	}

	pcl::PointCloud<SurfacePointT>::Ptr cloudSmoothedNormals(new pcl::PointCloud<SurfacePointT>());
	concatenateFields(*filtered, *cloudNormals, *cloudSmoothedNormals);

	pcl::Poisson<SurfacePointT> poisson;
	poisson.setDepth(9);
	poisson.setInputCloud(cloudSmoothedNormals);
	
	poisson.reconstruct(*_surface);
}

pcl::PolygonMeshPtr MyPoisson::GetMesh()
{
	return _surface;
}

pcl::PointCloud<PointT>::Ptr MyPoisson::GetCloud()
{
	return NULL;
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
	_normalSearchRadius = normalSearchRadius;
}

void MyPoisson::SetReconstructDepth(int depth)
{
	_depth = depth;
}

void MyPoisson::SetReconstructAlpha(double alpha)
{
	return;
}