package ex002.application;

import java.util.Scanner;

import ex002.model.entities.Quadrado;
import ex002.model.entities.Retangulo;
import ex002.model.entities.Triangulo;
import ex002.model.interfaces.AreaCalculavel;

public class App {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double lado, base, altura;

        lado = scan.nextDouble();
        AreaCalculavel q = new Quadrado(lado);

        lado = scan.nextDouble();
        altura = scan.nextDouble();
        AreaCalculavel r = new Retangulo(lado,altura);

        base = scan.nextDouble();
        altura = scan.nextDouble();
        AreaCalculavel t = new Triangulo(base,altura);

        System.out.println(q.calcularArea());
        System.out.println(r.calcularArea());
        System.out.println(t.calcularArea());

        scan.close();
    }
}
