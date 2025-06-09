package ex002.model.entities;

import ex002.model.interfaces.AreaCalculavel;

public class Retangulo implements AreaCalculavel{
    private double base, altura;

    public Retangulo(double base, double altura) {
        this.base = base;
        this.altura = altura;
    }

    @Override
    public double calcularArea(){
        return base*altura;
    }
}
