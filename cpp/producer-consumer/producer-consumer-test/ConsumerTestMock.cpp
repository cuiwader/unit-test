#include <vector>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <ChunkData.h>
#include <Consumer.h>

#include "MockDataQueue.h"

using std::vector;
using std::shared_ptr;
using namespace testing;

using namespace producer_consumer;

class ConsumerTestMock : public testing::Test
{
protected:
	ConsumerTestMock()
		: consumer(&queue)
	{
	}

	virtual void SetUp()
	{
	}

	MockDataQueue queue;

	Consumer consumer;
};

TEST_F(ConsumerTestMock, HandlePrimeNumberWithMock)
{
	EXPECT_CALL(queue, Dequeue())
		.Times(1)
		.WillOnce(Return(shared_ptr<ChunkData>(new ChunkData({ 1, 3, 7 }))));

	ASSERT_TRUE(consumer.Consume());
}

TEST_F(ConsumerTestMock, HandleBoundaryZeroWithMock)
{
	EXPECT_CALL(queue, Dequeue())
		.Times(1)
		.WillOnce(Return(shared_ptr<ChunkData>(new ChunkData({ 0, 0, 0 }))));

	EXPECT_FALSE(consumer.Consume());
}