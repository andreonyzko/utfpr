package com.mycompany.aula02;

import java.util.Scanner;

public class AULA02 {

    public static void main(String[] args) {
        ex001();
        ex002();
        ex003();
        ex004();
        ex005();
        ex006();
        ex007();
        ex008();
    }
    
    public static void ex001(){
        Scanner read= new Scanner(System.in);
        double media=0;
        for(int i=0; i<4; i++){
            media += read.nextDouble();
        }
        
        media /= 4;
        
        System.out.println(media);
    }
    
    public static void ex002(){
        Scanner read= new Scanner(System.in);
        double numero = read.nextDouble();
        System.out.println((int)numero);
    }
    
    public static void ex003(){
        Scanner read= new Scanner(System.in);
        int maior=0;
        for(int i=0; i<3; i++){
            int valor= read.nextInt();
            if(maior < valor){
                maior = valor;
            }
        }
        System.out.println(maior);
    }
    
    public static void ex004(){
        Scanner read= new Scanner(System.in);
        int numero = read.nextInt();
        for(int i=1; i<=numero; i++){
            System.out.print(i+" ");
        }
    }
    
    public static void ex005(){
        Scanner read= new Scanner(System.in);
        int numero = read.nextInt();
        for(int i=numero; i>=1; i--){
            System.out.print(i+" ");
        }
    }
    
    public static void ex006(){
        Scanner read = new Scanner(System.in);
        int quantidade=0, soma=0;
        while(1==1){
            int n= read.nextInt();
            quantidade++;
            if(n < 0) break;
            soma += n;
        }
        System.out.println("Quantidade = "+quantidade+"\nSoma = "+soma);
    }
    
    public static void ex007(){
        Scanner read = new Scanner(System.in);
        int opt = read.nextInt();
        switch (opt) {
            case 1:
                System.out.println("1 - Caixa");
                break;
            case 2:
                System.out.println("2 - Financiamento");
                break;
            case 3:
                System.out.println("3 - Empréstimo");
                break;    
            case 4:
                System.out.println("4 - Produtor Rural");
                break;
            case 5:
                System.out.println("5 - Abertura de Contas");
                break;
            case 6:
                System.out.println("6 - Falar com o Gerente");
                break;
            default:
                System.out.println(opt+" - Opção Inexistente");
        }
    }
    
    public static void ex008(){
        Scanner read = new Scanner(System.in);
        int i1=0, i2=0, i3=0, i4=0;
        while(true){
            int valor = read.nextInt();
            if(valor < 0) break;
            else if(valor <= 25) i1++;
            else if(valor > 25 && valor <= 50) i2++;
            else if(valor > 50 && valor <= 75) i3++;
            else if(valor > 75 && valor <= 100) i4++;
        }
        System.out.println("[0,25] = "+i1);
        System.out.println("[26,50] = "+i2);
        System.out.println("[51,75] = "+i3);
        System.out.println("[76,100] = "+i4);
        
    }
    
    
}
