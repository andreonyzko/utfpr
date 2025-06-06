import java.util.Scanner;

public class Ex002 {
    public static void main(String[] args) {
        Scanner read= new Scanner(System.in);
        double numero = read.nextDouble();
        System.out.println((int)numero);

        read.close();
    }
}
