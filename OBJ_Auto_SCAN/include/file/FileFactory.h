#ifndef FILE_FACTORY
#define FILE_FACTORY

#include "file/3DFile.h";
#include "file/objFile.h";
#include "file/plyFile.h";
#include "file/pcdFile.h";

typedef pcl::PointXYZRGBA PointT;

class FileFactory
{
public:
	FileFactory()
	{
	}

	ThreeDFile* GetObjFile(std::string dir = "")
	{
		ObjFile* file = new ObjFile(dir);
		return (ThreeDFile*)file;
	}

	ThreeDFile* GetPlyFile(std::string dir = "")
	{
		PlyFile* file = new PlyFile(dir);
		return (ThreeDFile*)file;
	}

	ThreeDFile* GetPcdFile(std::string dir = "")
	{
		PcdFile* file = new PcdFile(dir);
		return (ThreeDFile*)file;
	}
};

#endif