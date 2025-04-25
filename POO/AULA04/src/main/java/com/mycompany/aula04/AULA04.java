package com.mycompany.aula04;

import java.util.Scanner;

public class AULA04 {
    
    public static void main(String args[]){
        Aluno a1 = new Aluno();
        a1.print();

        Aluno aluno2 = new Aluno("Fulana", 'F', 20232323);
        aluno2.print();

        Pessoa p1 = new Pessoa();
        Pessoa p2 = new Pessoa("Aluno de Poo", 1.60, 90.5);
        System.out.printf("Nome: %s, Altura: %.2f, Peso: %.2f\n", p1.nome, p1.altura, p1. peso);
        System.out.printf("Nome: %s, Altura: %.2f, Peso: %.2f\n", p2.nome, p2.altura, p2. peso);

        p1 = new Pessoa("Aluno de Poo", 1.60, 90.5);
        System.out.printf("Nome: %s, Altura: %.2f, Peso: %.2f\n", p1.nome, p1.altura, p1. peso);
        System.out.printf("IMC: %.2f\n", p1.calcularIMC());
        
        p1 = new Pessoa("Pessoa1", 1.80, 75);
        System.out.printf("Nome: %s, Altura: %.2f, Peso: %.2f\n", p1.nome, p1.altura, p1. peso);
        System.out.printf("IMC: %.2f\n", p1.calcularIMC());
        System.out.printf("Classificação: %s\n", p1.classificacaoIMC());
    }
}
