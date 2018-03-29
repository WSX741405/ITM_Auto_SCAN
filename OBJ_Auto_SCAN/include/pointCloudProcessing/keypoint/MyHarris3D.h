#ifndef MY_HARRIS3D
#define MY_HARRIS3D

#include <pcl/keypoints/harris_3d.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
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
	void SetMethod(pcl::HarrisKeypoint3D<PointT, pcl::PointXYZI>::ResponseMethod method);
	pcl::PointCloud<pcl::PointXYZI>::Ptr GetResult();

private:
	pcl::HarrisKeypoint3D<PointT, pcl::PointXYZI>* _harris3D;
	pcl::PointCloud<pcl::PointXYZI>::Ptr _keypoints;

	float _radius;
	float _radiusSearch;
	pcl::HarrisKeypoint3D<PointT, pcl::PointXYZI>::ResponseMethod _method;
};

#endif