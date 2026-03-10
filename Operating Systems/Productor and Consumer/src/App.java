public class App {
    public static void main(String[] args){
        Thread productor = new Thread(() -> {
            try{
                for(int i = 1; i <= 10; i++){
                    Productor.produce(i);
                    System.out.printf("Produziu %d\n", i);
                    Thread.sleep(200);
                }
            }
            catch(Exception e){
                System.out.printf("Erro no produtor: %s\n", e.getMessage());
            };
        });

        Thread consumer = new Thread(() -> {
            try {
                for(int i = 10; i < 20; i++){
                    System.out.printf("Consumiu %d\n", Consumer.consume());
                    Thread.sleep(300);
                }
            } catch (Exception e) {
                System.out.printf("Erro no consumidor: %s", e.getMessage());
            }
        });

        productor.start();
        consumer.start();
    }
}