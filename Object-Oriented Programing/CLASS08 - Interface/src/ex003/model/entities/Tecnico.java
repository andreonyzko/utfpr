package ex003.model.entities;

import ex003.model.interfaces.Funcionario;

public class Tecnico extends FuncionarioClass implements Funcionario {
    private static double valorPorHora = 40;

    public Tecnico(String name, double CH){
        super(name, CH);
    }

    @Override
    public double calcularSalario() {
        return getCH()*valorPorHora;
    }
}
