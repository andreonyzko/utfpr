public class Productor {
    public static void produce(int item) throws Exception {
        Buffer.emptySlots.acquire();
        Buffer.mutex.acquire();

        Buffer.queue[Buffer.producePosition] = item;
        Buffer.producePosition++;
        if (Buffer.producePosition == 10)
            Buffer.producePosition = 0;
        Buffer.notReaded++;

        Buffer.mutex.release();
        Buffer.fullSlots.release();
    }
}
