#ifndef RECONSTRUCT_FACTORY
#define RECONSTRUCT_FACTORY

#include "ReconstructProcessing.h"
#include "GreedyProjection.h"
#include "MarchingCubes.h"

typedef pcl::PointXYZRGB PointT;

class ReconstructFactory
{
public:
	ReconstructFactory();
	ReconstructProcessing* GetGreedyProjection();
	ReconstructProcessing* GetMarchingCubes();

private:

};

#endif