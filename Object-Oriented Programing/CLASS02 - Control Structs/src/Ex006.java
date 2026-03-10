import java.util.Scanner;

public class Ex006 {
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        int quantidade=0, soma=0;
        while(true){
            int n= read.nextInt();
            quantidade++;
            if(n < 0) break;
            soma += n;
        }
        System.out.println("Quantidade = "+quantidade+"\nSoma = "+soma);
        read.close();
    }
}
