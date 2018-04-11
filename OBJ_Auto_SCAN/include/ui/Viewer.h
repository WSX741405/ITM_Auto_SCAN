#ifndef VIEWER
#define VIEWER

#include <pcl/visualization/cloud_viewer.h>
#include <vtkRenderWindow.h>
#include <pcl/surface/grid_projection.h>
#include <pcl/surface/gp3.h>
#include <pcl/features/normal_3d.h>

class Viewer
{
public:
	Viewer(std::string title = "") : _title(title)
	{
		_viewer.reset(new pcl::visualization::PCLVisualizer(_title, false));
	}

	void ShowPointCloud(pcl::PointCloud<PointT>::Ptr cloud, std::string name = "")
	{
		if (!_viewer->updatePointCloud(cloud, name))
			//_viewer->removeAllPointClouds();
			_viewer->addPointCloud(cloud, name);
	}

	void ShowSurface(pcl::PolygonMeshPtr surface, std::string name = "")
	{
		if (!_viewer->updatePolygonMesh(*surface, name))
			_viewer->addPolygonMesh(*surface, name);
	}

	void Show(pcl::PointCloud<PointT>::Ptr sourceCloud, pcl::PointCloud<PointT>::ConstPtr targetCloud, pcl::CorrespondencesPtr correspondences, std::string name = "")
	{
		_viewer->addCorrespondences<PointT>(sourceCloud, targetCloud, *correspondences, name);
	}

	void Clear()
	{
		_viewer->removeAllPointClouds();
	}

	void SetupInteractor(QVTKInteractor* interactor, vtkRenderWindow* renderWindow)
	{
		_viewer->setupInteractor(interactor, renderWindow);
	}

	vtkRenderWindow* GetRenderWindow()
	{
		return _viewer->getRenderWindow();
	}

	void AddCoordinateSystem(double coorSys)
	{
		_viewer->addCoordinateSystem(coorSys);
	}

private:
	std::string _title;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> _viewer;
};

#endif