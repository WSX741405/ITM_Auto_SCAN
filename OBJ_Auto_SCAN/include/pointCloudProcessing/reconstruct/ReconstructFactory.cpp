#include "ReconstructFactory.h"

ReconstructFactory::ReconstructFactory()
{

}

ReconstructProcessing* ReconstructFactory::GetGreedyProjection()
{
	static GreedyProjection* reconstruct = new GreedyProjection();
	return reconstruct;
}

ReconstructProcessing* ReconstructFactory::GetMarchingCubes()
{
	static MarchingCubes* reconstruct = new MarchingCubes();
	return reconstruct;
}

ReconstructProcessing* ReconstructFactory::GetPoisson()
{
	static MyPoisson* reconstruct = new MyPoisson();
	return reconstruct;
}