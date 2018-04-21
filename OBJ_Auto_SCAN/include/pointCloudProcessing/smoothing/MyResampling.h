#ifndef MY_RESAMPLING
#define MY_RESAMPLING

#include "Typedef.h"
#include <pcl/PolygonMesh.h>
#include <pcl/features/normal_3d_omp.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/surface/mls.h>

#include "SmoothingProcessing.h"

class MyResampling : public SmoothingProcessing
{
public:
	MyResampling();
	void Processing(pcl::PolygonMeshPtr mesh);
	void Processing(pcl::PointCloud<PointT>::Ptr cloud);
	pcl::PolygonMeshPtr GetMesh();
	pcl::PointCloud<PointT>::Ptr GetCloud();
	void SetNumIter(int numIter);
	void SetConvergence(double convergence);
	void SetRelaxationFactor(double relaxationFactor);
	void SetFeatureAngle(int featureAngle);
	void SetSearchRadius(double searchRadius);
	void SetUpsamplingRadius(double upsamplingRadius);
	void SetUpsamplingStepSize(double upsamplingStepSize);

private:
	pcl::PointCloud<SurfacePointT>::Ptr _result;

	double _searchRadius;
	double _upsamplingRadius;
	double _upsamplingStepSize;
};

#endif