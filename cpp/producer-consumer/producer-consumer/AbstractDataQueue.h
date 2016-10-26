#pragma once

#include <memory>

#include "ChunkData.h"

using std::shared_ptr;

namespace producer_consumer
{
	class AbstractDataQueue
	{
	public:
		virtual void Inqueue(shared_ptr<ChunkData>) = 0;

		virtual shared_ptr<ChunkData> Dequeue() = 0;

		virtual size_t Size() const = 0;

		virtual ~AbstractDataQueue() { }
	}; // class AbstractDataQueue

} // namespace producer_consumer

