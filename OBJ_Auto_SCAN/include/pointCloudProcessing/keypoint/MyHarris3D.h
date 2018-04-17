#ifndef MY_HARRIS3D
#define MY_HARRIS3D

#include <pcl/keypoints/harris_3d.h>
#include "Typedef.h"
#include "KeypointProcessing.h"

class MyHarris : public KeypointProcessing
{
public:
	MyHarris();
	void Processing(pcl::PointCloud<PointT>::Ptr cloud);
	void SetScales(float minScale, int nrOctaves, int nrScalesPerOctave);
	void SetMinContrast(float minContrast);
	void SetRadius(float radius);
	void SetRadiusSearch(float radiusSearch);
	void SetMethod(pcl::HarrisKeypoint3D<PointT, KeypointT>::ResponseMethod method);
	pcl::PointCloud<KeypointT>::Ptr GetResult();

private:
	pcl::HarrisKeypoint3D<PointT, KeypointT>* _harris3D;
	pcl::PointCloud<KeypointT>::Ptr _keypoints;

	float _radius;
	float _radiusSearch;
	pcl::HarrisKeypoint3D<PointT, KeypointT>::ResponseMethod _method;
	bool _nonMaxSupression;
};

#endif