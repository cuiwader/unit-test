package producer_consumer;

public class Consumer {

    private DataQueue queue;

    public Consumer(DataQueue queue) {
        this.queue = queue;
    }

    public boolean consume() {
        for (int n : queue.dequeue().GetData()) {
            if (isPrime(n)) {
                return true;
            }
        }
        return false;
    }

    boolean isPrime(int n) {
        for (int i = 1; i < n; i++) {
            if ((n % i) == 0) {
                return false;
            }
        }
        return true;
    }
}
