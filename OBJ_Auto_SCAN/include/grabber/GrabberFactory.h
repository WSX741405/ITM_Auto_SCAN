#ifndef  GRABBER_FACTORY
#define GRABBER_FACTORY

#include "grabber/Grabber.h"
#include "flexx/Flexx.h"
#include "rs/RS.h"

class IGrabber;
class Flexx;
class Realsense;

class GrabberFactory
{
public:
	GrabberFactory();
	~GrabberFactory();
	IGrabber* GetFlexxGrabber(ISubject* subject = NULL);
	IGrabber* GetRSGrabber(ISubject* subject = NULL);

private:
	Flexx* _flexx;
	Realsense* _rs;
};

#endif