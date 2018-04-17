#include "MyResampling.h"

MyResampling::MyResampling()
{
	_result.reset(new pcl::PointCloud<SurfacePointT>);

	_searchRadius = 0.03;
	_upsamplingRadius = 0.005;
	_upsamplingStepSize = 0.003;
}

void MyResampling::Processing(pcl::PolygonMeshPtr mesh)
{
	return;
}

void MyResampling::Processing(pcl::PointCloud<PointT>::Ptr cloud)
{
	pcl::search::KdTree<PointT>::Ptr tree(new pcl::search::KdTree<PointT>);
	pcl::MovingLeastSquares<PointT, SurfacePointT> mls;

	mls.setComputeNormals(true);

	// Set parameters
	mls.setInputCloud(cloud);
	mls.setPolynomialFit(true);
	mls.setSearchMethod(tree);
	mls.setSearchRadius(_searchRadius);
	mls.setUpsamplingRadius(_upsamplingRadius);
	mls.setUpsamplingStepSize(_upsamplingStepSize);

	// Reconstruct
	mls.process(*_result);
}

pcl::PolygonMeshPtr MyResampling::GetMeshResult()
{
	return NULL;
}

pcl::PointCloud<PointT>::Ptr MyResampling::GetCloudResult()
{
	pcl::PointCloud<PointT>::Ptr result;
	result.reset(new pcl::PointCloud<PointT>);
	for (int counter = 0; counter < _result->size(); counter++)
	{
		PointT* point = new PointT();
		point->x = _result->points[counter].x;
		point->y = _result->points[counter].y;
		point->z = _result->points[counter].z;

		point->r = _result->points[counter].r;
		point->g = _result->points[counter].g;
		point->b = _result->points[counter].b;
		result->push_back(*point);
	}
	return result;
}

void MyResampling::SetNumIter(int numIter)
{
	return;
}

void MyResampling::SetConvergence(double convergence)
{
	return;
}

void MyResampling::SetRelaxationFactor(double relaxationFactor)
{
	return;
}

void MyResampling::SetFeatureAngle(int featureAngle)
{
	return;
}

void MyResampling::SetSearchRadius(double searchRadius)
{
	_searchRadius = searchRadius;
}

void MyResampling::SetUpsamplingRadius(double upsamplingRadius)
{
	_upsamplingRadius = upsamplingRadius;
}

void MyResampling::SetUpsamplingStepSize(double upsamplingStepSize)
{
	_upsamplingStepSize = upsamplingStepSize;
}