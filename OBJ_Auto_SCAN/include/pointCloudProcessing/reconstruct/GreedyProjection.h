#ifndef GREEDY_PROJECTION
#define GREEDY_PROJECTION

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl /surface/grid_projection.h>
#include <pcl/surface/gp3.h>

#include "ReconstructProcessing.h"

class GreedyProjection : public ReconstructProcessing
{
public:
	GreedyProjection();
	void Processing();

private:

};

#endif