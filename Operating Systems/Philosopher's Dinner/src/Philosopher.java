import java.util.concurrent.Semaphore;

public class Philosopher implements Runnable {
    private int id;
    private Semaphore forkLeft;
    private Semaphore forkRight;

    public Philosopher(int id, Semaphore forkL, Semaphore forkR) {
        this.id = id;
        forkLeft = forkL;
        forkRight = forkR;
    }

    @Override
    public void run() {
        try {
            for (int j = 0; j < 3; j++) {
                System.out.printf("Filósofo %d está pensando\n", id);

                if (this.id == 4) {
                    forkRight.acquire();
                    forkLeft.acquire();
                } else {
                    forkLeft.acquire();
                    forkRight.acquire();
                }
                System.out.printf("Filósofo %d está jantando\n", id);

                forkLeft.release();
                forkRight.release();
                System.out.printf("Filósofo %d voltou a pensar\n", id);
            }
        } catch (Exception e) {
            Thread.currentThread().interrupt();
        }
    }
}
