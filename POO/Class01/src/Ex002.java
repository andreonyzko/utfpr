import java.util.Scanner;

public class Ex002 {
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        int i = read.nextInt();
        double d= read.nextDouble();
        String str= read.next();
        System.out.println(i);
        System.out.println(d);
        System.out.println(str);
        read.close();
    }
}
