import java.util.concurrent.Semaphore;

public class Buffer {
    static int[] queue = new int[10];
    static int producePosition = 0, consumePosition = 0, notReaded = 0;
    static Semaphore emptySlots = new Semaphore(10);
    static Semaphore fullSlots = new Semaphore(0);
    static Semaphore mutex = new Semaphore(1);
}