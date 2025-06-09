package ex003.model.entities;

import ex003.model.interfaces.Funcionario;

public class Professor extends FuncionarioClass implements Funcionario{
    private static double valorPorHora = 60;


    public Professor(String name, double CH){
        super(name, CH);
    }

    @Override
    public double calcularSalario() {
        return getCH()*valorPorHora;
    }
}
