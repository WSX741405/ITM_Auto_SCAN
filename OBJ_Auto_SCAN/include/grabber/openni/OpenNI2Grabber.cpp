#include "OpenNI2Grabber.h"

OpenNI2Grabber::OpenNI2Grabber(ISubject* subject) : _subject(subject)
{
	_grabber = new pcl::io::OpenNI2Grabber();
	_f = boost::bind(&OpenNI2Grabber::CloudCallback, this, _1);
	_connection = _grabber->registerCallback(_f);
}

void OpenNI2Grabber::StartCamera()
{
	_grabber->start();
}

void OpenNI2Grabber::StopCamera()
{
	_grabber->stop();
}

void OpenNI2Grabber::SetDepthConfidence(int depthConfidence)
{
	return;
}

std::mutex& OpenNI2Grabber::GetMutex()
{
	return _mutex;
}

void OpenNI2Grabber::CloudCallback(const pcl::PointCloud<PointT>::ConstPtr &cloud)
{
	std::unique_lock<std::mutex> lock(_mutex);
	pcl::PointCloud<PointT>::Ptr cpyCloud = boost::const_pointer_cast<pcl::PointCloud<PointT>>(cloud);
	/*
	int width = cloud->width;
	int height = cloud->height;
	pcl::PointCloud<PointT>::Ptr cpyCloud;
	cpyCloud.reset(new pcl::PointCloud<PointT>(width / 2, height / 2));
	for (int widthIndex = 0; widthIndex < width / 2; widthIndex++)
	{
		for (int heightIndex = 0; heightIndex < height / 2; heightIndex++)
		{
			PointT point(cloud->at(widthIndex, heightIndex));
			cpyCloud->at(widthIndex, heightIndex) = point;
		} 
	}*/
	_subject->NotifyObservers(cpyCloud);
	boost::this_thread::sleep(boost::posix_time::milliseconds(300));
}