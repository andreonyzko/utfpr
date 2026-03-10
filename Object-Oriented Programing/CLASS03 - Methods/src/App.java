import java.util.Scanner;

public class App {
    
    public static void main(String[] args) {
        double n = maior(1, 2, 3, 4);
        System.out.printf("%.1f", n);
        
        int vetor[] = {1,-2,3,4,-5,6,-7};
        int maior = procuraMaiorValor(vetor);
        System.out.println(maior);
        
        Scanner entrada = new Scanner(System.in);
        int tam = entrada.nextInt();
        int matriz[][] = new int[tam][tam];
        for (int i=0; i<tam; i++){
            for (int j=0; j<tam; j++){
                matriz[i][j] = entrada.nextInt();
            }
        }
        printDiagonalPrincipal(matriz);

        entrada.close();
    }
    
    public static int maior(int... numeros){
        int maior=numeros[0];
        for(int i=0; i<numeros.length; i++){
            if(numeros[i] > maior) maior = numeros[i];
        }
        
        return maior;
    }
    
    public static int procuraMaiorValor(int numeros[]){
        int maior=numeros[0];
        for(int i=0; i<numeros.length; i++){
            if(numeros[i] > maior) maior = numeros[i];
        }
        
        return maior;
    }
    
    public static void printDiagonalPrincipal(int matriz[][]){
        for(int i=0; i<matriz.length; i++){
            System.out.printf("%d ", matriz[i][i]);
        }
    }
}
