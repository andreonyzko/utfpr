import java.util.Scanner;

public class Ex005 {
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        String nome = read.next();
        String sobrenome = read.next();
        System.out.println(nome+" "+sobrenome);
        read.close();
    }
}
