#ifndef RECONSTRUCT_PROCESSING
#define RECONSTRUCT_PROCESSING

class ReconstructProcessing
{
public:
	virtual void Processing(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<PointT>::Ptr target) = 0;
	virtual pcl::PolygonMesh GetSurface() = 0;
	virtual void SetSearchRadius(double searchRadius) = 0;
	virtual void SetMu(double mu) = 0;
	virtual void SetMaxNearestNeighbors(int maxNearestNeighbors)= 0;
	virtual void SetMaxSurfaceAngle(double maxSurfaceAngle) = 0;
	virtual void SetMinAngle(double minAngle) = 0;
	virtual void SetMaxAngle(double maxAngle) = 0;

private:

};

#endif