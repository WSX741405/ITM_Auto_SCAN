#ifndef GREEDY_PROJECTION
#define GREEDY_PROJECTION

#include "Typedef.h"
#include <pcl/surface/grid_projection.h>
#include <pcl/surface/gp3.h>
#include <pcl/features/normal_3d.h>

#include "ReconstructProcessing.h"

class GreedyProjection : public ReconstructProcessing
{
public:
	GreedyProjection();
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
	pcl::PCLSurfaceBase<SurfacePointT>::Ptr _reconstructSurface;
	pcl::PolygonMeshPtr _surface;

	double _searchRadius;
	double _mu;
	int _maxNearestNeighbors;
	double _maxSurfaceAngle;
	double _minAngle;
	double _maxAngle;
	bool _normalConsistency;
	double _normalSearchRadius;
};

#endif