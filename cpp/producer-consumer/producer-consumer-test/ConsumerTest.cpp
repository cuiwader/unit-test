#include <vector>

#include <gtest/gtest.h>

#include <ChunkData.h>
#include <DataQueue.h>
#include <Consumer.h>

using namespace producer_consumer;
using std::vector;
using std::shared_ptr;

class ConsumerTest : public testing::Test
{
protected:
	ConsumerTest()
		: consumer(&queue)
	{
	}

	virtual void SetUp()
	{
	}

	DataQueue queue;

	Consumer consumer;
};

TEST_F(ConsumerTest, HandlePrimeNumber)
{
	queue.Inqueue(shared_ptr<ChunkData>(new ChunkData({ 1, 3, 7 })));

	ASSERT_TRUE(consumer.Consume());
	ASSERT_EQ(0, queue.Size());
}

TEST_F(ConsumerTest, HandleBoundaryZero)
{
	queue.Inqueue(shared_ptr<ChunkData>(new ChunkData({ 0, 0, 0 })));

	Consumer consumer(&queue);
	EXPECT_FALSE(consumer.Consume());
	EXPECT_EQ(0, queue.Size());
}