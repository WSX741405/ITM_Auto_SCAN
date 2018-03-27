#ifndef FILTER_FACTORY
#define FILTER_FACTORY

#include "FilterProcessing.h"
#include "VoxelGridFilter.h"

class FilterFactory
{
public:
	FilterFactory();
	FilterProcessing* GetVoixelGridFilter();
private:

};

#endif