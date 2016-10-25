#pragma once

#include <memory>
#include <queue>

#include "ChunkData.h"

using std::queue;
using std::shared_ptr;

namespace producer_consumer
{
	class DataQueue
	{
	public:
		DataQueue();

		void Inqueue(shared_ptr<ChunkData>);

		shared_ptr<ChunkData> Dequeue();

		size_t Size();

		virtual ~DataQueue();

	private:
		queue<shared_ptr<ChunkData>> queue;
	}; // class DataQueue

} // namespace producer_consumer

