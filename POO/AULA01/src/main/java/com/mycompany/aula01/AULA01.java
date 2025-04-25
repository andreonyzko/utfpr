package com.mycompany.aula01;

import java.util.Scanner;

public class AULA01 {
    public static void main(String[] args) {
        ex001();
        ex002();
        ex003();
        ex004();
        ex005();
    }
    
    public static void ex001() {
        System.out.println("Meu Primeiro Programa Java");
    }
    
    public static void ex002() {
        Scanner read = new Scanner(System.in);
        int i = read.nextInt();
        double d= read.nextDouble();
        String str= read.next();
        System.out.println(i);
        System.out.println(d);
        System.out.println(str);
    }
    
    public static void ex003() {
        Scanner read = new Scanner(System.in);
        int number = read.nextInt();
        System.out.println(number*number);
    }
    
    public static void ex004(){
        Scanner read = new Scanner(System.in);
        int n1= read.nextInt();
        int n2= read.nextInt();
        System.out.println("soma = "+(n1+n2));
        System.out.println("subtracao = "+(n1-n2));
    }
    
    public static void ex005(){
        Scanner read = new Scanner(System.in);
        String nome = read.next();
        String sobrenome = read.next();
        System.out.println(nome+" "+sobrenome);
    }
}
