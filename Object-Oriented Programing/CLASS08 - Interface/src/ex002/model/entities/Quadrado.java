package ex002.model.entities;

import ex002.model.interfaces.AreaCalculavel;

public class Quadrado implements AreaCalculavel {
    private double lado;

    public Quadrado(double lado) {
        this.lado = lado;
    }
    
    @Override
    public double calcularArea(){
        return lado*lado;
    }
}
