#ifndef OBSERVER_FACTORY
#define OBSERVER_FACTORY

#include "observer/IObserver.h"

class ISubject;

class SubjectFactory
{
public:
	SubjectFactory()
	{
	}
	ISubject* GetFlexxSubject();
	ISubject* GetRSSubject();
	ISubject* GetOpenNI2Subject();
};

#endif