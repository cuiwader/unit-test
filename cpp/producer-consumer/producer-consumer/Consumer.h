#pragma once

#include "DataQueue.h"

namespace producer_consumer
{

	class Consumer
	{
	public:
		Consumer(DataQueue* queue);

		virtual ~Consumer();

		/*
		 * get one ChunkData from queue and return true if there is a prime
		 */
		bool Consume();

	private:
		bool IsPrime(unsigned int n);

		DataQueue* queue;
	}; // class Consumer

}  // namespace producer_consumer