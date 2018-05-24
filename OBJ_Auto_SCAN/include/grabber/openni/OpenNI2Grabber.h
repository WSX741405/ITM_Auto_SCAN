#ifndef OPENNI_GRABBER_2
#define OPENNI_GRABBER_2

#include <pcl/io/openni2_grabber.h>
#include "grabber/Grabber.h"
#include "observer/IObserver.h"
#include "Typedef.h"

class OpenNI2Grabber : public IGrabber
{
public:
	OpenNI2Grabber(ISubject* subject);
	void StartCamera();
	void StopCamera();
	void SetDepthConfidence(int depthConfidence);
	std::mutex& GetMutex();

private:
	void CloudCallback(const pcl::PointCloud<PointT>::ConstPtr &cloud);

	std::mutex _mutex;
	pcl::Grabber* _grabber;
	boost::signals2::connection _connection;
	boost::function<void(const pcl::PointCloud<PointT>::ConstPtr&)> _f;

	ISubject* _subject;
};

#endif