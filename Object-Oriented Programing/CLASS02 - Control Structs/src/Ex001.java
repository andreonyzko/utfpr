import java.util.Scanner;

public class Ex001 {
    public static void main(String[] args) {
        Scanner read= new Scanner(System.in);
        double media=0;
        for(int i=0; i<4; i++){
            media += read.nextDouble();
        }
        
        media /= 4;
        
        System.out.println(media);

        read.close();
    }
}
