package producer_consumer;

import java.util.LinkedList;
import java.util.Queue;

public class DataQueue {

    private Queue<ChunkData> queue;

    public DataQueue() {
        this.queue = new LinkedList<ChunkData>();
    }

    public void inqueue(ChunkData data) {
        queue.add(data);
    }

    public ChunkData dequeue() {
        return queue.remove();
    }
}
