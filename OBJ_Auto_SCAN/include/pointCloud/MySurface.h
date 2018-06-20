#ifndef MY_SURFACE
#define MY_SURFACE

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/surface/grid_projection.h>
#include <pcl/surface/gp3.h>
#include <pcl/features/normal_3d.h>

#include "ui/Viewer.h"
#include "pointCloud/PointCloudElement.h"

class MySurface : public PointCloudElement
{
public:
	MySurface(pcl::PolygonMeshPtr surface, std::string name = "Name")
	{
		_surface.reset(new pcl::PolygonMesh(*surface));
		_name = name;
		_isSelected = false;		//default
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

	void Delete(Viewer& viewer)
	{
		viewer.DeletePointCloud(_name);
	}
	
	void Save(MyFile* file)
	{
		file->SaveFile(_surface);
	}

	pcl::PointCloud<KeypointT>::Ptr GetKeyPoint()
	{
		return NULL;
	}

	pcl::PointCloud<PointT>::Ptr GetPointCloud()
	{
		return NULL;
	}

	pcl::PolygonMeshPtr GetMesh()
	{
		return _surface;
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
	pcl::PolygonMeshPtr _surface;
};

#endif