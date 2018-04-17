#ifndef MY_SIFT3D
#define MY_SIFT3D

#include <pcl/keypoints/sift_keypoint.h>
#include "Typedef.h"
#include "KeypointProcessing.h"

class MySIFT : public KeypointProcessing
{
public:
	MySIFT();
	void Processing(pcl::PointCloud<PointT>::Ptr cloud);
	void SetScales(float minScale, int nrOctaves, int nrScalesPerOctave);
	void SetMinContrast(float minContrast);
	void SetRadius(float radius);
	void SetRadiusSearch(float radiusSearch);
	pcl::PointCloud<KeypointT>::Ptr GetResult();
	
private:
	pcl::SIFTKeypoint<PointT, KeypointT>* _sift3D;
	pcl::PointCloud<KeypointT>::Ptr _keypoints;

	float _minContrast;
	float _minScale;
	int _nrOctaves;
	int _nrScalesPerOctave;
};

#endif