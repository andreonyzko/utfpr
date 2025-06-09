package ex002.model.entities;

import ex002.model.interfaces.AreaCalculavel;

public class Triangulo implements AreaCalculavel{
    private double base, altura;

    public Triangulo(double base, double altura) {
        this.base = base;
        this.altura = altura;
    }

    @Override
    public double calcularArea() {
        return (base*altura)/2;
    }
}
