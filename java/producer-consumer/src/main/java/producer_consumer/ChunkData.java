package producer_consumer;

public class ChunkData {

    private int[] data;

    public ChunkData(int[] data) {
        this.data = data;
    }

    public int[] GetData() {
        return this.data;
    }
}
