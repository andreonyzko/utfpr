import java.util.Scanner;

public class Ex004 {
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        int n1= read.nextInt();
        int n2= read.nextInt();
        System.out.println("soma = "+(n1+n2));
        System.out.println("subtracao = "+(n1-n2));
        read.close();
    }
}
