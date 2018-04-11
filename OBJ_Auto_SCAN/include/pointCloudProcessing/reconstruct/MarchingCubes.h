#ifndef MARCHING_CUBES
#define MARCHING_CUBES

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/surface/marching_cubes_hoppe.h>
#include <pcl/features/normal_3d.h>

#include "ReconstructProcessing.h"

typedef pcl::PointXYZRGB PointT;
typedef pcl::PointXYZRGBNormal SurfacePointT;

class MarchingCubes : public ReconstructProcessing
{
public:
	MarchingCubes();
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

private:
	pcl::PCLSurfaceBase<pcl::PointXYZRGBNormal>::Ptr _reconstructSurface;
	pcl::PolygonMeshPtr _surface;

	int _gridResolutionX;
	int _gridResolutionY;
	int _gridResolutionZ;
	float _isoLevel;
	float _normalSearchRadius;
};

#endif