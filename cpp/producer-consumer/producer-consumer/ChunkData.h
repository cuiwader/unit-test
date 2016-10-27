#pragma once

#include <vector>

using std::vector;

namespace producer_consumer
{

	class ChunkData
	{
	public:
		ChunkData(vector<unsigned int> data);

		virtual ~ChunkData();

		const vector<unsigned int>& GetData() const;

	private:
		vector<unsigned int> data;
	}; // class DataChunk

} // namespace producer_consumer