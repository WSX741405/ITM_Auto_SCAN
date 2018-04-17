#include "SmoothingFactory.h"

SmoothingFactory::SmoothingFactory()
{
}

SmoothingProcessing* SmoothingFactory::GetMeshSmoothingLaplacian()
{
	static MeshSmoothingLaplacian* smoothing = new MeshSmoothingLaplacian();
	return smoothing;
}

SmoothingProcessing* SmoothingFactory::GetResampling()
{
	static MyResampling* smoothing = new MyResampling();
	return smoothing;
}