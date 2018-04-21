#ifndef SMOOTHING_PROCESSING
#define SMOOTHING_PROCESSING

#include "Typedef.h"
#include <pcl/PolygonMesh.h>

class SmoothingProcessing
{
public:
	virtual void Processing(pcl::PolygonMeshPtr mesh) = 0;
	virtual void Processing(pcl::PointCloud<PointT>::Ptr cloud) = 0;
	virtual pcl::PolygonMeshPtr GetMesh() = 0;
	virtual pcl::PointCloud<PointT>::Ptr GetCloud() = 0;
	virtual void SetNumIter(int numIter) = 0;
	virtual void SetConvergence(double convergence) = 0;
	virtual void SetRelaxationFactor(double relaxationFactor) = 0;
	virtual void SetFeatureAngle(int featureAngle) = 0;
	virtual void SetSearchRadius(double searchRadius) = 0;
	virtual void SetUpsamplingRadius(double upsamplingRadius) = 0;
	virtual void SetUpsamplingStepSize(double upsamplingStepSize) = 0;

private:

};

#endif