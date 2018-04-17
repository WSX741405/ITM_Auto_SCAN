#ifndef MESH_SMOOTHING_LAPLACIAN
#define MESH_SMOOTHING_LAPLACIAN

#include "Typedef.h"
#include <pcl/PolygonMesh.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/concave_hull.h>
#include <pcl/surface/vtk_smoothing/vtk.h>
#include <pcl/surface/vtk_smoothing/vtk_mesh_smoothing_laplacian.h>
#include <pcl/surface/vtk_smoothing/vtk_utils.h>
#include <vtkSmartPointer.h>
#include <vtkSmoothPolyDataFilter.h>

#include "SmoothingProcessing.h"

class MeshSmoothingLaplacian : public SmoothingProcessing
{
public:
	MeshSmoothingLaplacian();
	void Processing(pcl::PolygonMeshPtr mesh);
	void Processing(pcl::PointCloud<PointT>::Ptr cloud);
	pcl::PolygonMeshPtr GetMeshResult();
	pcl::PointCloud<PointT>::Ptr GetCloudResult();
	void SetNumIter(int numIter);
	void SetConvergence(double convergence);
	void SetRelaxationFactor(double relaxationFactor);
	void SetFeatureAngle(int featureAngle);
	void SetSearchRadius(double searchRadius);
	void SetUpsamplingRadius(double upsamplingRadius);
	void SetUpsamplingStepSize(double upsamplingStepSize);

private:
	pcl::PolygonMeshPtr _result;

	int _numItr; 
	double _convergence;
	double _relaxationFactor;
	bool _featureEdgeSmoothing;
	double _featureAngle;
	bool _boundarySmoothing;
};

#endif