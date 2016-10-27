package producer_consumer;

import static org.hamcrest.CoreMatchers.is;
import static org.junit.Assert.assertThat;
import static org.mockito.Mockito.times;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;
import org.mockito.runners.MockitoJUnitRunner;

@RunWith(MockitoJUnitRunner.class)
public class ConsumerTestMockito {

    private Consumer consumer;

    @Mock
    private DataQueue queue;

    @BeforeClass
    public static void globalSetUp() {
        // TODO put class level set up here
    }

    @AfterClass
    public static void globalTearDown() {
        // TODO put class level tear down here
    }

    @Before
    public void setUp() {
        MockitoAnnotations.initMocks(this);
        this.consumer = new Consumer(queue);
    }

    @After
    public void tearDown() {
        // TODO put method level tear down here
    }

    @Test
    public void handlePrimeNumber() {
        when(queue.dequeue()).thenReturn(new ChunkData(new int[] { 1, 3, 7 }));
        assertThat(consumer.consume(), is(true));
        verify(queue, times(1)).dequeue();
    }

    @Test
    public void HandleBoundaryZero() {
        when(queue.dequeue()).thenReturn(new ChunkData(new int[] { 0, 0, 0 }));
        assertThat(consumer.consume(), is(false));
        verify(queue, times(1)).dequeue();
    }

}
