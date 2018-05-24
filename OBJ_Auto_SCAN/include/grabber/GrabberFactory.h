#ifndef  GRABBER_FACTORY
#define GRABBER_FACTORY

#include "grabber/Grabber.h"
#include "flexx/Flexx.h"
#include "rs/RS.h"
#include "openni/OpenNI2Grabber.h"

class IGrabber;
class Flexx;
class Realsense;
class OpenNI2Grabber;

class GrabberFactory
{
public:
	GrabberFactory();
	~GrabberFactory();
	IGrabber* GetFlexxGrabber(ISubject* subject = NULL);
	IGrabber* GetRSGrabber(ISubject* subject = NULL);
	IGrabber* GetOpenNI2Grabber(ISubject* subject = NULL);

private:
	Flexx* _flexx;
	Realsense* _rs;
	OpenNI2Grabber* _openni;
};

#endif