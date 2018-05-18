#ifndef KINFU_COMMON
#define KINFU_COMMON

#include <iostream>
#include <vector>

#include <pcl/console/parse.h>

#include <boost/filesystem.hpp>

#include <pcl/gpu/kinfu/kinfu.h>
#include <pcl/gpu/kinfu/raycaster.h>
#include <pcl/gpu/kinfu/marching_cubes.h>
#include <pcl/gpu/containers/initialization.h>

#include <pcl/common/time.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/image_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/io/vtk_io.h>
#include <pcl/io/openni_grabber.h>
#include <pcl/io/oni_grabber.h>
#include <pcl/io/pcd_grabber.h>
#include <pcl/exceptions.h>

#include "pcl/gpu/kinfu/tools/openni_capture.h"
#include <pcl/visualization/point_cloud_color_handlers.h>
#include "pcl/gpu/kinfu/tools/evaluation.h"

#include <pcl/common/angles.h>

#include "pcl/gpu/kinfu/tools/tsdf_volume.h"
#include "pcl/gpu/kinfu/tools/tsdf_volume.hpp"

#include "pcl/gpu/kinfu/tools/camera_pose.h"

#include "pcl/gpu/kinfu/internal.h"

typedef pcl::ScopeTime ScopeTimeT;

namespace pcl
{
	namespace gpu
	{
		void paint3DView(const KinfuTracker::View& rgb24, KinfuTracker::View& view, float colors_weight = 0.5f);
		void mergePointNormal(const DeviceArray<PointXYZ>& cloud, const DeviceArray<Normal>& normals, DeviceArray<PointNormal>& output);
	}

	namespace visualization
	{
		//////////////////////////////////////////////////////////////////////////////////////
		/** \brief RGB handler class for colors. Uses the data present in the "rgb" or "rgba"
		* fields from an additional cloud as the color at each point.
		* \author Anatoly Baksheev
		* \ingroup visualization
		*/
		template <typename PointT>
		class PointCloudColorHandlerRGBCloud : public PointCloudColorHandler<PointT>
		{
			using PointCloudColorHandler<PointT>::capable_;
			using PointCloudColorHandler<PointT>::cloud_;

			typedef typename PointCloudColorHandler<PointT>::PointCloud::ConstPtr PointCloudConstPtr;
			typedef typename pcl::PointCloud<RGB>::ConstPtr RgbCloudConstPtr;

		public:
			typedef boost::shared_ptr<PointCloudColorHandlerRGBCloud<PointT> > Ptr;
			typedef boost::shared_ptr<const PointCloudColorHandlerRGBCloud<PointT> > ConstPtr;

			/** \brief Constructor. */
			PointCloudColorHandlerRGBCloud(const PointCloudConstPtr& cloud, const RgbCloudConstPtr& colors)
				: rgb_(colors)
			{
				cloud_ = cloud;
				capable_ = true;
			}

			/** \brief Obtain the actual color for the input dataset as vtk scalars.
			* \param[out] scalars the output scalars containing the color for the dataset
			* \return true if the operation was successful (the handler is capable and
			* the input cloud was given as a valid pointer), false otherwise
			*/
			virtual bool
				getColor(vtkSmartPointer<vtkDataArray> &scalars) const
			{
				if (!capable_ || !cloud_)
					return (false);

				if (!scalars)
					scalars = vtkSmartPointer<vtkUnsignedCharArray>::New();
				scalars->SetNumberOfComponents(3);

				vtkIdType nr_points = vtkIdType(cloud_->points.size());
				reinterpret_cast<vtkUnsignedCharArray*>(&(*scalars))->SetNumberOfTuples(nr_points);
				unsigned char* colors = reinterpret_cast<vtkUnsignedCharArray*>(&(*scalars))->GetPointer(0);

				// Color every point
				if (nr_points != int(rgb_->points.size()))
					std::fill(colors, colors + nr_points * 3, static_cast<unsigned char> (0xFF));
				else
					for (vtkIdType cp = 0; cp < nr_points; ++cp)
					{
						int idx = cp * 3;
						colors[idx + 0] = rgb_->points[cp].r;
						colors[idx + 1] = rgb_->points[cp].g;
						colors[idx + 2] = rgb_->points[cp].b;
					}
				return (true);
			}

		private:
			virtual std::string
				getFieldName() const { return ("additional rgb"); }
			virtual std::string
				getName() const { return ("PointCloudColorHandlerRGBCloud"); }

			RgbCloudConstPtr rgb_;
		};
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class KinFuAppMethos
{
public:
	static void setViewerPose(pcl::visualization::PCLVisualizer& viewer, const Eigen::Affine3f& viewer_pose)
	{
		Eigen::Vector3f pos_vector = viewer_pose * Eigen::Vector3f(0, 0, 0);
		Eigen::Vector3f look_at_vector = viewer_pose.rotation() * Eigen::Vector3f(0, 0, 1) + pos_vector;
		Eigen::Vector3f up_vector = viewer_pose.rotation() * Eigen::Vector3f(0, -1, 0);
		viewer.setCameraPosition(pos_vector[0], pos_vector[1], pos_vector[2],
			look_at_vector[0], look_at_vector[1], look_at_vector[2],
			up_vector[0], up_vector[1], up_vector[2]);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	static Eigen::Affine3f getViewerPose(pcl::visualization::PCLVisualizer& viewer)
	{
		Eigen::Affine3f pose = viewer.getViewerPose();
		Eigen::Matrix3f rotation = pose.linear();

		Eigen::Matrix3f axis_reorder;
		axis_reorder << 0, 0, 1,
			-1, 0, 0,
			0, -1, 0;

		rotation = rotation * axis_reorder;
		pose.linear() = rotation;
		return pose;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	template<typename MergedT, typename PointT>
	static typename pcl::PointCloud<MergedT>::Ptr merge(const pcl::PointCloud<PointT>& points, const pcl::PointCloud<pcl::RGB>& colors)
	{
		typename pcl::PointCloud<MergedT>::Ptr merged_ptr(new pcl::PointCloud<MergedT>());

		pcl::copyPointCloud(points, *merged_ptr);
		for (size_t i = 0; i < colors.size(); ++i)
			merged_ptr->points[i].rgba = colors.points[i].rgba;

		return merged_ptr;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	static boost::shared_ptr<pcl::PolygonMesh> convertToMesh(const pcl::gpu::DeviceArray<pcl::PointXYZ>& triangles)
	{
		if (triangles.empty())
			return boost::shared_ptr<pcl::PolygonMesh>();

		pcl::PointCloud<pcl::PointXYZ> cloud;
		cloud.width = (int)triangles.size();
		cloud.height = 1;
		triangles.download(cloud.points);

		boost::shared_ptr<pcl::PolygonMesh> mesh_ptr(new pcl::PolygonMesh());
		pcl::toPCLPointCloud2(cloud, mesh_ptr->cloud);

		mesh_ptr->polygons.resize(triangles.size() / 3);
		for (size_t i = 0; i < mesh_ptr->polygons.size(); ++i)
		{
			pcl::Vertices v;
			v.vertices.push_back(i * 3 + 0);
			v.vertices.push_back(i * 3 + 2);
			v.vertices.push_back(i * 3 + 1);
			mesh_ptr->polygons[i] = v;
		}
		return mesh_ptr;
	}
};
#endif