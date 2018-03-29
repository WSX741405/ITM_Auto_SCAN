#include "FilterFactory.h"

FilterFactory::FilterFactory()
{
}

FilterProcessing* FilterFactory::GetVoixelGridFilter()
{
	static VoxelGridFilter* filter = new VoxelGridFilter();
	return filter;
}

FilterProcessing* FilterFactory::GetBoundingBoxFilter()
{
	static BoundingBoxFilter* filter = new BoundingBoxFilter();
	return filter;
}