#include "KeypointFactory.h"

KeypointFactory::KeypointFactory()
{
}

KeypointProcessing* KeypointFactory::GetSIFT()
{
	static MySIFT* sift = new MySIFT();
	return sift;
}

KeypointProcessing* KeypointFactory::GetHarris()
{
	static MyHarris* harris = new MyHarris();
	harris->SetMethod(pcl::HarrisKeypoint3D<PointT, KeypointT>::HARRIS);
	return harris;
}

KeypointProcessing* KeypointFactory::GetTomasi()
{
	static MyHarris* harris = new MyHarris();
	harris->SetMethod(pcl::HarrisKeypoint3D<PointT, KeypointT>::TOMASI);
	return harris;
}

KeypointProcessing* KeypointFactory::GetNoble()
{
	static MyHarris* harris = new MyHarris();
	harris->SetMethod(pcl::HarrisKeypoint3D<PointT, KeypointT>::NOBLE);
	return harris;
}

KeypointProcessing* KeypointFactory::Lowe()
{
	static MyHarris* harris = new MyHarris();
	harris->SetMethod(pcl::HarrisKeypoint3D<PointT, KeypointT>::LOWE);
	return harris;
}

KeypointProcessing* KeypointFactory::Curvature()
{
	static MyHarris* harris = new MyHarris();
	harris->SetMethod(pcl::HarrisKeypoint3D<PointT, KeypointT>::CURVATURE);
	return harris;
}