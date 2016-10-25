#include <vector>

#include "ChunkData.h"

namespace producer_consumer
{

	ChunkData::ChunkData(vector<unsigned int> data)
		: data(data)
	{
	}


	ChunkData::~ChunkData()
	{
	}

	const vector<unsigned int>& ChunkData::GetData()
	{
		return data;
	}
}
