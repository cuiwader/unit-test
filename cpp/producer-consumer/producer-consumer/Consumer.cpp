#include "Consumer.h"

namespace producer_consumer {

	Consumer::Consumer(AbstractDataQueue* queue)
		: queue(queue)
	{
	}


	Consumer::~Consumer()
	{
	}

	bool Consumer::Consume()
	{
		shared_ptr<ChunkData> data = queue->Dequeue();

		for (auto const& value : data->GetData()) {
			if (IsPrime(value)) {
				return true;
			}
		}
		return false;
	}

	bool Consumer::IsPrime(unsigned int n)
	{
		for (unsigned int i = 1; i < n; i++) {
			if ((n % i) == 0) {
				return false;
			}
		}
		return true;
	}

}  // namespace producer_consumer