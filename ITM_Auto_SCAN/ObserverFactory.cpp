#include "observer/ObserverFactory.h"

ISubject* SubjectFactory::GetFlexxSubject()
{
	static FlexxSubject* subject = new FlexxSubject();
	return (ISubject*)subject;
}

ISubject* SubjectFactory::GetRSSubject()
{
	static RSSubject* subject = new RSSubject();
	return (ISubject*)subject;
}