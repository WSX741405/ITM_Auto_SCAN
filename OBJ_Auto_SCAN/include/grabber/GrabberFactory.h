#ifndef  GRABBER_FACTORY
#define GRABBER_FACTORY

#include "grabber/Grabber.h"
#include "flexx/Flexx.h"
#include "rs/RS.h"
#include "openni/OpenniGrabber.h"

class IGrabber;
class Flexx;
class Realsense;
class MyOpenniGrabber;

class GrabberFactory
{
public:
	GrabberFactory();
	~GrabberFactory();
	IGrabber* GetFlexxGrabber(ISubject* subject = NULL);
	IGrabber* GetRSGrabber(ISubject* subject = NULL);
	IGrabber* GetOpenniGrabber(ISubject* subject = NULL);

private:
	Flexx* _flexx;
	Realsense* _rs;
	MyOpenniGrabber* _openni;
};

#endif