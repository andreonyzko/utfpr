import java.util.Scanner;

public class Ex003 {
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        int number = read.nextInt();
        System.out.println(number*number);
        read.close();
    }
}
