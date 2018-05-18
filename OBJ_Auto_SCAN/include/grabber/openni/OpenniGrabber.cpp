#include "OpenniGrabber.h"

MyOpenniGrabber::MyOpenniGrabber(ISubject* subject) : _subject(subject)
{
	//_grabber = new pcl::OpenNIGrabber();
	//_f = boost::bind(&MyOpenniGrabber::CloudCallback, this, _1);
	//_grabber->registerCallback(_f);
}

void MyOpenniGrabber::StartCamera()
{
	//_grabber->start();
}

void MyOpenniGrabber::StopCamera()
{
	//_grabber->stop();
}

void MyOpenniGrabber::SetDepthConfidence(int depthConfidence)
{
	return;
}

std::mutex& MyOpenniGrabber::GetMutex()
{
	return _mutex;
}

void MyOpenniGrabber::CloudCallback(const pcl::PointCloud<PointT>::ConstPtr &cloud)
{
	std::unique_lock<std::mutex> lock(_mutex);
	pcl::PointCloud<PointT>::Ptr cpyCloud = boost::const_pointer_cast<pcl::PointCloud<PointT>>(cloud);
	_subject->NotifyObservers(cpyCloud);
}