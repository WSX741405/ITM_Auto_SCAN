#ifndef MY_OPENNI_GRABBER
#define MY_OPENNI_GRABBER

#define HAVE_OPENNI

#include <pcl/io/openni_grabber.h>
#include "grabber/Grabber.h"
#include "observer/IObserver.h"
#include "Typedef.h"

class MyOpenniGrabber : public IGrabber
{
public:
	MyOpenniGrabber(ISubject* subject);
	void StartCamera();
	void StopCamera();
	void SetDepthConfidence(int depthConfidence);
	std::mutex& GetMutex();

private:
	void CloudCallback(const pcl::PointCloud<PointT>::ConstPtr &cloud);

	std::mutex _mutex;
	pcl::Grabber* _grabber;
	boost::function<void(const pcl::PointCloud<PointT>::ConstPtr&)> _f;

	ISubject* _subject;
};

#endif