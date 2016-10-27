package producer_consumer;

import static org.hamcrest.CoreMatchers.is;
import static org.junit.Assert.assertThat;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

public class ConsumerTest {

    private static Consumer consumer;

    private static DataQueue queue;

    @BeforeClass
    public static void globalSetUp() {
        ConsumerTest.queue = new DataQueue();
        ConsumerTest.consumer = new Consumer(queue);
    }

    @AfterClass
    public static void globalTearDown() {
        // TODO put class level tear down here
    }

    @Before
    public void setUp() {
        // TODO put method level set up here
    }

    @After
    public void tearDown() {
        // TODO put method level tear down here
    }

    @Test
    public void handlePrimeNumber() {
        queue.inqueue(new ChunkData(new int[] { 1, 3, 7 }));
        assertThat(consumer.consume(), is(true));
    }

    @Test
    public void HandleBoundaryZero() {
        queue.inqueue(new ChunkData(new int[] { 0, 0, 0 }));
        assertThat(consumer.consume(), is(false));
    }

}
