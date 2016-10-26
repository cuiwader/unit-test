#pragma once

#include <memory>

#include <gmock/gmock.h>

#include "ChunkData.h"
#include "AbstractDataQueue.h"

using std::shared_ptr;
using namespace producer_consumer;

class MockDataQueue : public AbstractDataQueue
{
public:
	MOCK_METHOD1(Inqueue, void(shared_ptr<ChunkData>));

	MOCK_METHOD0(Dequeue, shared_ptr<ChunkData>());

	MOCK_CONST_METHOD0(Size, unsigned int());

}; // class MockDataQueue

