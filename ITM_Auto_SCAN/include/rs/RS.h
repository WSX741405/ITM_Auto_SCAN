#ifndef  RS
#define RS

#include<pcl/io/ply_io.h>

#include "rs/rsgrabber/real_sense_grabber.h"
#include "observer/IObserver.h"

typedef pcl::PointXYZRGBA PointT;

class ISubject;

class Realsense
{
public:
	Realsense(ISubject* subject, std::string deviceId = "");
	~Realsense();
	void StartCamera();
	void StopCamera();
private:
	void CloudCallback(boost::shared_ptr<const pcl::PointCloud<PointT>> cloud);

	mutable boost::mutex _mutex;
	boost::function<void(const boost::shared_ptr<const pcl::PointCloud<PointT>>&)> _function;
	boost::signals2::connection _connection;
	pcl::RealSenseGrabber* _grabber;
	boost::shared_ptr<pcl::PointCloud<PointT>> _cloud;
};

#endif