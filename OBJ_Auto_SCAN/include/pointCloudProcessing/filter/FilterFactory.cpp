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

FilterProcessing* FilterFactory::GetOutlierRemovalFilter()
{
	static OutlierRemovalFilter* filter = new OutlierRemovalFilter();
	return filter;
}

FilterProcessing* FilterFactory::GetDepthImageBoundingBoxFilter()
{
	static DepthImageBoundingBoxFilter* filter = new DepthImageBoundingBoxFilter();
	return filter;
}