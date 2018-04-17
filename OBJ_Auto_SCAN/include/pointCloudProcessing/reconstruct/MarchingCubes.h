#ifndef MARCHING_CUBES
#define MARCHING_CUBES

#include "Typedef.h"
#include <pcl/surface/marching_cubes_hoppe.h>
#include <pcl/features/normal_3d.h>

#include "ReconstructProcessing.h"

class MarchingCubes : public ReconstructProcessing
{
public:
	MarchingCubes();
	void Processing(pcl::PointCloud<PointT>::Ptr cloud);
	pcl::PolygonMeshPtr GetResult();
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
	pcl::PCLSurfaceBase<SurfacePointT>::Ptr _reconstructSurface;
	pcl::PolygonMeshPtr _surface;

	int _gridResolutionX;
	int _gridResolutionY;
	int _gridResolutionZ;
	float _isoLevel;
	float _normalSearchRadius;
};

#endif