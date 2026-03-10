public class Consumer {
    public static int consume() throws Exception {
        Buffer.fullSlots.acquire();
        Buffer.mutex.acquire();

        int item = Buffer.queue[Buffer.consumePosition];
        Buffer.consumePosition++;
        if (Buffer.consumePosition == 10)
            Buffer.consumePosition = 0;
        Buffer.notReaded--;

        Buffer.mutex.release();
        Buffer.emptySlots.release();

        return item;
    }
}