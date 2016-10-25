#include <vector>

#include <gtest/gtest.h>

#include <ChunkData.h>
#include <DataQueue.h>
#include <Consumer.h>

using namespace producer_consumer;
using std::vector;

TEST(Consumer_test, HandlePrimeNumber)
{
	vector<unsigned int> raw = { 1, 3, 7 };
	shared_ptr<ChunkData> data(new ChunkData(raw));

	DataQueue queue;
	queue.Inqueue(data);

	Consumer consumer(&queue);
	ASSERT_TRUE(consumer.Consume());
}

TEST(Consumer_test, HandleBoundaryZero)
{
	vector<unsigned int> raw = { 0, 0, 0 };
	shared_ptr<ChunkData> data(new ChunkData(raw));

	DataQueue queue;
	queue.Inqueue(data);

	Consumer consumer(&queue);
	ASSERT_FALSE(consumer.Consume());
}