#include "rs/RS.h"

Realsense::Realsense(ISubject* subject, std::string deviceId) : _subject(subject)
{
	_grabber = new pcl::RealSenseGrabber(deviceId);
	_function = boost::bind(&Realsense::CloudCallback, this, _1);
}

Realsense::~Realsense()
{
	_connection.disconnect();
}

void Realsense::StartCamera()
{
	_connection = _grabber->registerCallback(_function);
	_grabber->start();
}

void Realsense::StopCamera()
{
	_grabber->stop();
}

void Realsense::CloudCallback(boost::shared_ptr<const pcl::PointCloud<PointT>> cloud)
{
	boost::mutex::scoped_lock lock(_mutex);
	boost::shared_ptr<pcl::PointCloud<PointT>> cpyCloud = boost::const_pointer_cast<pcl::PointCloud<PointT>>(cloud);
	_subject->NotifyObservers(cpyCloud);
}