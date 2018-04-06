#include "RegestrationFactory.h"

RegestrationFactory::RegestrationFactory()
{

}

RegestrationProcessing* RegestrationFactory::GetICP()
{
	static MyICP* regestration = new MyICP();
	return regestration;
}