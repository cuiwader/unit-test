#pragma once

#include <memory>
#include <queue>

#include "ChunkData.h"
#include "AbstractDataQueue.h"

using std::queue;
using std::shared_ptr;

namespace producer_consumer
{
	class DataQueue : public AbstractDataQueue
	{
	public:
		DataQueue();

		virtual void Inqueue(shared_ptr<ChunkData>) override;

		virtual shared_ptr<ChunkData> Dequeue() override;

		virtual size_t Size() const override;

		virtual ~DataQueue();

	private:
		queue<shared_ptr<ChunkData>> queue;
	}; // class DataQueue

} // namespace producer_consumer

