#ifndef MY_SHOTRGB
#define MY_SHOTRGB

#include "Typedef.h"
#include <pcl/features/normal_3d.h>
#include <pcl/features/shot.h>
#include <pcl/features/shot_omp.h>
#include <pcl/registration/correspondence_rejection_sample_consensus.h>
#include <pcl/registration/icp.h>
#include <pcl/features/normal_3d_omp.h>
#include <pcl/filters/filter.h>

#include "CorrespondencesProcessing.h"

class MySHOTRGB : public CorrespondencesProcessing
{
public:
	MySHOTRGB();
	void Processing(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<KeypointT>::Ptr sourceKpts, pcl::PointCloud<PointT>::Ptr target, pcl::PointCloud<KeypointT>::Ptr targetKpts);
	void SetDescriptorRadius(float descriptorRadiusSearch);
	void SetDescriptorKSearch(int kSearch);
	void SetNormalRadius(float normalRadiusSearch);
	void SetCorrespondencesK(float correspondencesK);
	void SetRejectorInlierThreshold(float rejectorInlierThreshold);
	pcl::CorrespondencesPtr GetCorrespondencesResult();
	pcl::PointCloud<PointT>::Ptr GetResult();

private:
	pcl::PointCloud<pcl::SHOT1344>::Ptr ProessingDescriptor(pcl::PointCloud<PointT>::Ptr cloud, pcl::PointCloud<KeypointT>::Ptr keypoints);
	std::vector<int> ProcessingCorrespondences(pcl::PointCloud<pcl::SHOT1344>::Ptr source, pcl::PointCloud<pcl::SHOT1344>::Ptr target);
	pcl::CorrespondencesPtr ProcessingFilterCorrespondences(pcl::PointCloud<KeypointT>::Ptr sourceKpts, pcl::PointCloud<KeypointT>::Ptr targetKpts, std::vector<int> source2Target, std::vector<int> target2Source);
	void DetermineInitialTransformation(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<KeypointT>::Ptr sourceKpts, pcl::PointCloud<KeypointT>::Ptr targetKpts, pcl::CorrespondencesPtr correspondences);

	pcl::PointCloud<pcl::SHOT1344>::Ptr _sourceDescriptor;
	pcl::PointCloud<pcl::SHOT1344>::Ptr _targetDescriptor;
	pcl::PointCloud<PointT>::Ptr _transformedSource;
	pcl::CorrespondencesPtr _correspondencesResult;

	float _descriptorRadiusSearch;
	float _normalRadiusSearch;
	int _correspondencesK;
	float _rejectorInlierThreshold;
};

#endif