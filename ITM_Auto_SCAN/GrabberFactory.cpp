#include "grabber/GrabberFactory.h"

IGrabber* GrabberFactory::GetRSGrabber(ISubject* subject)
{
	static Realsense* rs = new Realsense(subject);
	return (IGrabber*)rs;
}

IGrabber* GrabberFactory::GetFlexxGrabber(ISubject* subject)
{
	static Flexx* flexx = new Flexx(subject);
	return (IGrabber*)flexx;
}