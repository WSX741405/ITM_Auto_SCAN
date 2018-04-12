#ifndef GREEDY_PROJECTION
#define GREEDY_PROJECTION

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/surface/grid_projection.h>
#include <pcl/surface/gp3.h>
#include <pcl/features/normal_3d.h>

#include "ReconstructProcessing.h"

typedef pcl::PointXYZRGB PointT;
typedef pcl::PointXYZRGBNormal SurfacePointT;

class GreedyProjection : public ReconstructProcessing
{
public:
	GreedyProjection();
	void Processing(pcl::PointCloud<PointT>::Ptr cloud);
	pcl::PolygonMeshPtr GetSurface();
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

private:
	pcl::PCLSurfaceBase<pcl::PointXYZRGBNormal>::Ptr _reconstructSurface;
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