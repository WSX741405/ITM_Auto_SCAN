#ifndef  GRABBER_FACTORY
#define GRABBER_FACTORY

#include "grabber/Grabber.h"
#include "flexx/Flexx.h"
#include "rs/RS.h"

typedef pcl::PointXYZRGBA PointT;

class IGrabber;

class GrabberFactory
{
public:
	GrabberFactory()
	{
	}
	IGrabber* GetRSGrabber(ISubject* subject = nullptr);
	IGrabber* GetFlexxGrabber(ISubject* subject = nullptr);
};

#endif