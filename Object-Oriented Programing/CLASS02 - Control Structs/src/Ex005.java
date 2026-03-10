import java.util.Scanner;

public class Ex005 {
    public static void main(String[] args) {
        Scanner read= new Scanner(System.in);
        int numero = read.nextInt();
        for(int i=numero; i>=1; i--){
            System.out.print(i+" ");
        }
        read.close();
    }
}
