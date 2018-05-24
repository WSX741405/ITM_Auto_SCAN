#include "observer/ObserverFactory.h"

ISubject* SubjectFactory::GetFlexxSubject()
{
	static GrabberSubject* subject = new GrabberSubject();
	return (ISubject*)subject;
}

ISubject* SubjectFactory::GetRSSubject()
{
	static GrabberSubject* subject = new GrabberSubject();
	return (ISubject*)subject;
}

ISubject* SubjectFactory::GetOpenNI2Subject()
{
	static GrabberSubject* subject = new GrabberSubject();
	return (ISubject*)subject;
}