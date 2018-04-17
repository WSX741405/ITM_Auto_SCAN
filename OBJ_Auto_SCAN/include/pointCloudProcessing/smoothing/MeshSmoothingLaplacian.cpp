#include "MeshSmoothingLaplacian.h"

MeshSmoothingLaplacian::MeshSmoothingLaplacian()
{
	_result.reset(new pcl::PolygonMesh());
	_numItr = 20000;
	_convergence = 0.0001;
	_relaxationFactor = 0.0001;
	_featureEdgeSmoothing = true;
	_featureAngle = M_PI / 6;
	_boundarySmoothing = true;
}

void MeshSmoothingLaplacian::Processing(pcl::PolygonMeshPtr mesh)
{
	pcl::MeshSmoothingLaplacianVTK vtk;
	vtk.setInputMesh(mesh);
	vtk.setNumIter(_numItr);
	vtk.setConvergence(_convergence);
	vtk.setRelaxationFactor(_relaxationFactor);
	vtk.setFeatureEdgeSmoothing(_featureEdgeSmoothing);
	vtk.setFeatureAngle(_featureAngle);
	vtk.setBoundarySmoothing(_boundarySmoothing);
	vtk.process(*_result);
}

void MeshSmoothingLaplacian::Processing(pcl::PointCloud<PointT>::Ptr cloud)
{
	return;
}

pcl::PolygonMeshPtr MeshSmoothingLaplacian::GetMeshResult()
{
	return _result;
}

pcl::PointCloud<PointT>::Ptr MeshSmoothingLaplacian::GetCloudResult()
{
	return NULL;
}

void MeshSmoothingLaplacian::SetNumIter(int numIter)
{
	_numItr = numIter;
}

void MeshSmoothingLaplacian::SetConvergence(double convergence)
{
	_convergence = convergence;
}

void MeshSmoothingLaplacian::SetRelaxationFactor(double relaxationFactor)
{
	_relaxationFactor = relaxationFactor;
}

void MeshSmoothingLaplacian::SetFeatureAngle(int featureAngle)
{
	_featureAngle = featureAngle * M_PI / 180;
}

void MeshSmoothingLaplacian::SetSearchRadius(double searchRadius)
{
	return;
}

void MeshSmoothingLaplacian::SetUpsamplingRadius(double upsamplingRadius)
{
	return;
}

void MeshSmoothingLaplacian::SetUpsamplingStepSize(double upsamplingStepSize)
{
	return;
}