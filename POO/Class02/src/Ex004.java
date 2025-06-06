import java.util.Scanner;

public class Ex004 {
    public static void main(String[] args) {
        Scanner read= new Scanner(System.in);
        int numero = read.nextInt();
        for(int i=1; i<=numero; i++){
            System.out.print(i+" ");
        }
        read.close();
    }
}
