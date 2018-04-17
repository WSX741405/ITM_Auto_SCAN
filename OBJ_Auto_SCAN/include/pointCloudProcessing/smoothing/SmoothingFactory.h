#ifndef SMOOTHING_FACTORY
#define SMOOTHING_FACTORY

#include "MeshSmoothingLaplacian.h"
#include "MyResampling.h"
#include "SmoothingProcessing.h"

class SmoothingFactory
{
public:
	SmoothingFactory();
	SmoothingProcessing* GetMeshSmoothingLaplacian();
	SmoothingProcessing* GetResampling();

private:

};

#endif