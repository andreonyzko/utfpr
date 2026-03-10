import java.util.concurrent.Semaphore;

public class App {
    public static void main(String[] args) throws Exception {
        Semaphore[] forks = new Semaphore[5];
        for(int i=0; i<5; i++) forks[i] = new Semaphore(1);

        Philosopher[] philosophers = new Philosopher[5];
        for(int i=0; i<5; i++){
            if(i == 4){
                philosophers[i] = new Philosopher(i, forks[i], forks[0]);
            }
            else{
                philosophers[i] = new Philosopher(i, forks[i], forks[i+1]);
            }

            new Thread(philosophers[i]).start();
        }
    }
}
