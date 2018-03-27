#ifndef FILE_FACTORY
#define FILE_FACTORY

#include "file/MyFile.h";
#include "file/objFile.h";
#include "file/plyFile.h";
#include "file/pcdFile.h";

class FileFactory
{
public:
	FileFactory()
	{
	}

	MyFile* GetFileByFilter(std::string dir, std::string filter)
	{
		if (filter == std::string("OBJ(*.obj)"))
		{
			return GetObjFile(dir);
		}
		else if (filter == std::string("PLY(*.ply)"))
		{
			return GetPlyFile(dir);
		}
		else if (filter == std::string("PCD(*.pcd)"))
		{
			return GetPcdFile(dir);
		}
		return NULL;
	}

	MyFile* GetObjFile(std::string dir)
	{
		ObjFile* file = new ObjFile(dir);
		return (MyFile*)file;
	}

	MyFile* GetPlyFile(std::string dir)
	{
		PlyFile* file = new PlyFile(dir);
		return (MyFile*)file;
	}

	MyFile* GetPcdFile(std::string dir)
	{
		PcdFile* file = new PcdFile(dir);
		return (MyFile*)file;
	}
};

#endif