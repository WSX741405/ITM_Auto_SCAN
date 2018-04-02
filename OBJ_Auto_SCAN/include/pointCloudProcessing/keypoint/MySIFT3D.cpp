#include "MySIFT3D.h"

MySIFT::MySIFT()
{
	_sift3D = NULL;
	_keypoints.reset(new pcl::PointCloud<KeypointT>());

	//		Default
	_minScale = 0.01f;
	_nrOctaves = 3;
	_nrScalesPerOctave = 2;
	_minContrast = 0.0;
}

void MySIFT::Processing(pcl::PointCloud<PointT>::Ptr cloud)
{
	_sift3D = new pcl::SIFTKeypoint<PointT, KeypointT>();
	boost::shared_ptr<pcl::Keypoint<PointT, KeypointT> > keypointDetector;
	_sift3D->setScales(_minScale, _nrOctaves, _nrScalesPerOctave);
	_sift3D->setMinimumContrast(_minContrast);
	keypointDetector.reset(_sift3D);
	keypointDetector->setInputCloud(cloud);
	keypointDetector->compute(*_keypoints);
}

void MySIFT::SetScales(float minScale, int nrOctaves, int nrScalesPerOctave)
{
	_minScale = minScale;
	_nrOctaves = nrOctaves;
	_nrScalesPerOctave = nrScalesPerOctave;
}

void MySIFT::SetMinContrast(float minContrast)
{
	_minContrast = minContrast;
}

void MySIFT::SetRadius(float radius)
{
	return;
}

void MySIFT::SetRadiusSearch(float radiusSearch)
{
	return;
}

pcl::PointCloud<KeypointT>::Ptr MySIFT::GetResult()
{
	return _keypoints;
}