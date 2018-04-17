#ifndef KEYPOINT_PROCESSING
#define KEYPOINT_PROCESSING

#include <pcl/keypoints/sift_keypoint.h>
#include "Typedef.h"

class KeypointProcessing
{
public:
	virtual void Processing(pcl::PointCloud<PointT>::Ptr cloud) = 0;
	virtual pcl::PointCloud<KeypointT>::Ptr GetResult() = 0;
	virtual void SetScales(float minScale, int nrOctaves, int nrScalesPerOctave) = 0;
	virtual void SetMinContrast(float minContrast) = 0;
	virtual void SetRadius(float radius) = 0;
	virtual void SetRadiusSearch(float radiusSearch) = 0;

protected:
};

#endif