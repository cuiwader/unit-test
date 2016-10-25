#include <memory>

#include "ChunkData.h"
#include "DataQueue.h"

namespace producer_consumer
{

	DataQueue::DataQueue()
	{
	}

	DataQueue::~DataQueue()
	{
	}

	void DataQueue::Inqueue(shared_ptr<ChunkData> data)
	{
		queue.push(data);
	}

	shared_ptr<ChunkData> DataQueue::Dequeue()
	{
		shared_ptr<ChunkData> data = queue.front();
		queue.pop();
		return data;
	}

}  // namespace producer_consumer