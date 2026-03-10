import java.util.Scanner;

public class Ex003 {
    public static void main(String[] args) {
        Scanner read= new Scanner(System.in);
        
        int maior=0;
        for(int i=0; i<3; i++){
            int valor= read.nextInt();
            if(maior < valor){
                maior = valor;
            }
        }
        System.out.println(maior);
        read.close();
    }
}
