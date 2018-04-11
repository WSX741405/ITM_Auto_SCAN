#ifndef POINT_CLOUD_ELEMENTS
#define POINT_CLOUD_ELEMENTS

#include <vector>
#include "PointCloudElement.h"
#include "MyPointCloud.h"
#include "MyKeypoint.h"
#include "MySurface.h"

typedef pcl::PointXYZRGB PointT;
typedef pcl::PointXYZI KeypointT;

class PointCloudElements
{
public:
	PointCloudElements()
	{
		_elements = std::vector<PointCloudElement*>();
	}

	void AddPointCloudElement(PointCloudElement* element)
	{
		_elements.push_back(element);
	}

	void ShowPointCloudElementById(Viewer& viewer, int id)
	{
		_elements[id]->Show(viewer);
	}

	void RemoveSelectedPointCloud()
	{
		for (int counter = 0; counter < GetNumberOfElements(); counter++)
		{
			if (_elements[counter]->GetIsSelected())
			{
				_elements.erase(_elements.begin() + counter);
				counter--;
			}
		}
	}

	void RemoveAllPointCloud()
	{
		_elements.clear();
	}

	void SelectAllPointCloud()
	{
		for (int counter = 0; counter < GetNumberOfElements(); counter++)
		{
			_elements[counter]->SetIsSelected(true);
		}
	}

	void UnselectAllPointCloud()
	{
		for (int counter = 0; counter < GetNumberOfElements(); counter++)
		{
			_elements[counter]->SetIsSelected(false);
		}
	}

	bool IsNameExist(std::string name)
	{
		for (int counter = 0; counter < GetNumberOfElements(); counter++)
		{
			if (name == _elements[counter]->GetName())
				return true;
		}
		return false;
	}

	std::vector<PointCloudElement*> GetElementsByIsSelected()
	{
		std::vector<PointCloudElement*> outputClouds;
		for (int counter = 0; counter < GetNumberOfElements(); counter++)
		{
			if (_elements[counter]->GetIsSelected())
			{
				outputClouds.push_back(_elements[counter]);
			}
		}
		return outputClouds;
	}

	//	id = 0 ~ size - 1
	std::string GetNameById(int id)
	{
		return _elements[id]->GetName();
	}

	void SetIsSelectedById(int id, bool isSelected)
	{
		_elements[id]->SetIsSelected(isSelected);
	}

	bool GetIsSelectedById(int id)
	{
		return _elements[id]->GetIsSelected();
	}

	int GetNumberOfElements()
	{
		return _elements.size();
	}

private:
	std::vector<PointCloudElement*> _elements;
};

#endif