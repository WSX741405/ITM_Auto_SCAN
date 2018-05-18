#include "grabber/GrabberFactory.h"

GrabberFactory::GrabberFactory() : _flexx(NULL), _rs(NULL), _openni(NULL)
{
}

GrabberFactory::~GrabberFactory()
{
	if (_flexx != NULL)
		delete _flexx;
	if (_rs != NULL)
		delete _rs;
	if (_openni = NULL)
		delete _openni;
}

IGrabber* GrabberFactory::GetFlexxGrabber(ISubject* subject)
{
	if (_flexx == NULL)
	{
		if (subject != NULL)
			_flexx = new Flexx(subject);
	}
	return (IGrabber*)_flexx;
}

IGrabber* GrabberFactory::GetRSGrabber(ISubject* subject)
{
	if (_rs == NULL)
	{
		if (subject != NULL)
			_rs = new Realsense(subject);
	}
	return (IGrabber*)_rs;
}

IGrabber* GrabberFactory::GetOpenniGrabber(ISubject* subject)
{
	if (_openni == NULL)
	{
		if (subject != NULL)
			_openni = new MyOpenniGrabber(subject);
	}
	return (IGrabber*)_openni;
}