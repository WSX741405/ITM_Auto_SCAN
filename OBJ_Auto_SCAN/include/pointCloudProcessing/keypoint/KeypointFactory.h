#ifndef KEYPOINT_FACTORY
#define KEYPOINT_FACTORY

#include <pcl/keypoints/harris_3d.h>

#include "KeypointProcessing.h"
#include "MySIFT3D.h"
#include "MyHarris3D.h"

class KeypointFactory
{
public:
	KeypointFactory();
	KeypointProcessing* GetSIFT();
	KeypointProcessing* GetHarris();
	KeypointProcessing* GetTomasi();
	KeypointProcessing* GetNoble();
	KeypointProcessing* Lowe();
	KeypointProcessing* Curvature();

private:

};

#endif