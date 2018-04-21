#ifndef MY_POISSON
#define MY_POISSON

#include "Typedef.h"
#include <pcl/filters/passthrough.h>
#include <pcl/surface/poisson.h>

#include "ReconstructProcessing.h"

class MyPoisson : public ReconstructProcessing
{
public:
	MyPoisson();
	void Processing(pcl::PointCloud<PointT>::Ptr cloud);
	pcl::PolygonMeshPtr GetMesh();
	pcl::PointCloud<PointT>::Ptr GetCloud();
	void SetSearchRadius(double searchRadius);
	void SetMu(double mu);
	void SetMaxNearestNeighbors(int maxNearestNeighbors);
	void SetMaxSurfaceAngle(double maxSurfaceAngle);
	void SetMinAngle(double minAngle);
	void SetMaxAngle(double maxAngle);
	void SetGridResolution(int gridResolutionX, int gridResolutionY, int gridResolutionZ);
	void SetIsoLevel(float isoLevel);
	void SetNormalSearchRadius(double normalSearchRadius);
	void SetReconstructDepth(int depth);
	void SetReconstructAlpha(double alpha);

private:
	pcl::PolygonMeshPtr _surface;

	double _normalSearchRadius;
	int _depth;
};

#endif