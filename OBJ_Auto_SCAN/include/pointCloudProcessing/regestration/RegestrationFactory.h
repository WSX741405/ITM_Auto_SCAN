#ifndef REGESTRATION_FACTORY
#define REGESTRATION_FACTORY

#include "RegestrationProcessing.h"
#include "MyICP.h"

class RegestrationFactory
{
public:
	RegestrationFactory();
	RegestrationProcessing* GetICP();

private:

};



#endif