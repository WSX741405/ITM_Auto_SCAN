#ifndef MY_SURFACE
#define MY_SURFACE

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/surface/grid_projection.h>
#include <pcl/surface/gp3.h>
#include <pcl/features/normal_3d.h>

#include "ui/Viewer.h"
#include "pointCloud/PointCloudElement.h"

typedef pcl::PointXYZRGB PointT;

class MySurface : public PointCloudElement
{
public:
	MySurface(pcl::PolygonMesh surface, std::string name = "Name")
	{
		_surface = surface;
		_name = name;
	}

	std::string GetName()
	{
		return _name;
	}

	void Show(Viewer& viewer)
	{
		//viewer.ShowPointCloud(GetPointCloud(), GetName());
		viewer.ShowSurface(_surface, _name);
	}

	pcl::PointCloud<PointT>::Ptr GetPointCloud()
	{
		return NULL;
	}

	void SetIsSelected(bool isSelected)
	{
		_isSelected = isSelected;
	}

	bool GetIsSelected()
	{
		return _isSelected;
	}

private:
	pcl::PolygonMesh _surface;
};

#endif