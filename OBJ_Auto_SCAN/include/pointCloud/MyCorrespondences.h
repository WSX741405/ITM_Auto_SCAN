#ifndef MY_CORRESPONDENCES
#define MY_CORRESPONDENCES

#include "Typedef.h"
#include "PointCloudElement.h"

class MyCorrespondences : public PointCloudElement
{
public:
	MyCorrespondences(MyKeyPoint* source, MyKeyPoint* target, pcl::CorrespondencesPtr correspondences, std::string name = "Name")
	{
		_source = source;
		_target = target;
		_correspondences.reset(new pcl::Correspondences(*correspondences));
		_name = name;
		_isSelected = false;		//default
	}

	std::string GetName()
	{
		return _name;
	}
	void SetIsSelected(bool isSelected)
	{
		_isSelected = isSelected;
	}

	bool GetIsSelected()
	{
		return _isSelected;
	}

	void Show(Viewer& viewer)
	{
		_source->Show(viewer);
		_target->Show(viewer);
		viewer.Show(_source->GetKeyPoint(), _target->GetKeyPoint(), _correspondences, _name);
	}

	void Delete(Viewer& viewer)
	{
		_source->Delete(viewer);
		_target->Delete(viewer);
		viewer.DeleteCorrespondence(_name);
	}

	void Save(MyFile* file)
	{
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
		return NULL;
	}

private:
	MyKeyPoint* _source;
	MyKeyPoint* _target;
	pcl::CorrespondencesPtr _correspondences;

};

#endif