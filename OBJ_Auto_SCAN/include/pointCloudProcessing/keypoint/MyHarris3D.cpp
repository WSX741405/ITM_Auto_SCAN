#include "MyHarris3D.h"

MyHarris::MyHarris()
{
	_harris3D = NULL;
	_keypoints.reset(new pcl::PointCloud<KeypointT>());

	//	default
	_radius = 0.01;
	_radiusSearch = 0.01;
	_nonMaxSupression = true;
}

void MyHarris::Processing(pcl::PointCloud<PointT>::Ptr cloud)
{
	_harris3D = new pcl::HarrisKeypoint3D<PointT, KeypointT>();
	_harris3D->setMethod(_method);
	boost::shared_ptr<pcl::Keypoint<PointT, KeypointT> > keypointDetector;
	_harris3D->setNonMaxSupression(_nonMaxSupression);
	_harris3D->setRadius(_radius);
	_harris3D->setRadiusSearch(_radiusSearch);
	keypointDetector.reset(_harris3D);
	keypointDetector->setInputCloud(cloud);
	keypointDetector->compute(*_keypoints);
}

void MyHarris::SetScales(float minScale, int nrOctaves, int nrScalesPerOctave)
{
	return;
}

void MyHarris::SetMinContrast(float minContrast)
{
	return;
}

void MyHarris::SetRadius(float radius)
{
	_radius = radius;
}

void MyHarris::SetRadiusSearch(float radiusSearch)
{
	_radiusSearch = radiusSearch;
}

void MyHarris::SetMethod(pcl::HarrisKeypoint3D<PointT, KeypointT>::ResponseMethod method)
{
	_method = method;
}

pcl::PointCloud<KeypointT>::Ptr MyHarris::GetResult()
{
	return _keypoints;
}