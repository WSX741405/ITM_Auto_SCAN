#include "RS.h"

Realsense::Realsense(ISubject* subject, std::string deviceId) : _subject(subject)
{
	_grabber = new pcl::RealSenseGrabber(deviceId);
	_function = boost::bind(&Realsense::CloudCallback, this, _1);
	_connection = _grabber->registerCallback(_function);
}

Realsense::~Realsense()
{
	_connection.disconnect();
}

void Realsense::StartCamera()
{
	_grabber->start();
}

void Realsense::StopCamera()
{
	_grabber->stop();
}

void Realsense::CloudCallback(boost::shared_ptr<const pcl::PointCloud<PointT>> cloud)
{
	std::unique_lock<std::mutex> lock(_mutex);
	pcl::PointCloud<PointT>::Ptr cpyCloud = boost::const_pointer_cast<pcl::PointCloud<PointT>>(cloud);
	_subject->NotifyObservers(cpyCloud);
}

void Realsense::SetDepthConfidence(int depthConfidence)
{
	throw std::string("Realsense: No support depth confidence");
}

std::mutex& Realsense::GetMutex()
{
	return _mutex;
}