#ifndef FILTER_FACTORY
#define FILTER_FACTORY

#include "FilterProcessing.h"
#include "VoxelGridFilter.h"
#include "BoundingBoxFilter.h"

class FilterFactory
{
public:
	FilterFactory();
	FilterProcessing* GetVoixelGridFilter();
	FilterProcessing* GetBoundingBoxFilter();

private:

};

#endif