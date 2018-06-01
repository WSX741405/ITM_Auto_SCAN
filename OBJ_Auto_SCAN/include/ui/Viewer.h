#ifndef VIEWER
#define VIEWER

#include <pcl/visualization/cloud_viewer.h>
#include <vtkRenderWindow.h>
#include <pcl/surface/grid_projection.h>
#include <pcl/surface/gp3.h>
#include <pcl/features/normal_3d.h>
#include <QVTKInteractor.h>

class Viewer
{
public:
	Viewer(std::string title = "") : _title(title)
	{
		_viewer.reset(new pcl::visualization::PCLVisualizer(_title, false));
	}

	~Viewer()
	{
		_viewer.reset();
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

	void Show(pcl::PointCloud<KeypointT>::Ptr sourceCloud, pcl::PointCloud<KeypointT>::Ptr targetCloud, pcl::CorrespondencesPtr correspondences, std::string name = "")
	{
		_viewer->addCorrespondences<KeypointT>(sourceCloud, targetCloud, *correspondences, name);
	}

	void DeletePointCloud(std::string id)
	{
		_viewer->removePointCloud(id);
	}

	void DeleteCorrespondence(std::string id)
	{
		_viewer->removeCorrespondences(id);
	}

	void Clear()
	{
		_viewer->removeAllPointClouds();
		_viewer->removeAllShapes();
	}

	void SetBackgroundColor(int r, int g, int b)
	{
		_viewer->setBackgroundColor(r, g, b);
	}

	void SetupInteractor(QVTKInteractor* interactor, vtkRenderWindow* renderWindow)
	{
		_viewer->setupInteractor(interactor, renderWindow);
	}

	vtkRenderWindow* GetRenderWindow()
	{
		return _viewer->getRenderWindow();
	}

	void AddCoordinateSystem(double coorSys, float x = 0, float y = 0, float z = 0)
	{
		_viewer->addCoordinateSystem(coorSys, x, y, z);
	}

private:
	std::string _title;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> _viewer;
};

#endif