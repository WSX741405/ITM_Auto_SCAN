#include "FilterFactory.h"

FilterFactory::FilterFactory()
{
}

FilterProcessing* FilterFactory::GetVoixelGridFilter()
{
	VoxelGridFilter* filter = new VoxelGridFilter();
	return filter;
}