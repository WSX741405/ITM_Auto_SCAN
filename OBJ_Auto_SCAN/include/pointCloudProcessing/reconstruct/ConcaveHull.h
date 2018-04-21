#ifndef CONCAVE_HULL
#define CONCAVE_HULL

#include "Typedef.h"
#include "ReconstructProcessing.h"

#include <pcl/filters/project_inliers.h>
#include <pcl/surface/concave_hull.h>

class ConcaveHull : public ReconstructProcessing
{
public:
	ConcaveHull();
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
	//pcl::PolygonMeshPtr _surface;
	pcl::PointCloud<PointT>::Ptr _cloud;

	double _alpha;
};

#endif