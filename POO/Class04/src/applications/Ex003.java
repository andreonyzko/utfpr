package applications;

import entities.Pessoa;

public class Ex003 {
    public static void main(String[] args) {
        Pessoa p1 = new Pessoa("Aluno de Poo", 1.60, 90.5);
        System.out.printf("Nome: %s, Altura: %.2f, Peso: %.2f\n", p1.nome, p1.altura, p1. peso);
        System.out.printf("IMC: %.2f\n", p1.calcularIMC());

        Pessoa p2 = new Pessoa("Aluno de Poo", 1.80, 75);
        System.out.printf("Nome: %s, Altura: %.2f, Peso: %.2f\n", p2.nome, p2.altura, p2. peso);
        System.out.printf("IMC: %.2f\n", p2.calcularIMC());
    }
}
