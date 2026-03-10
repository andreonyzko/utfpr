package ex003.model.entities;

import ex003.model.interfaces.Funcionario;

public class Estagiario extends FuncionarioClass implements Funcionario {
    private static double valorPorHora = 12.5;

    public Estagiario(String name, double CH){
        super(name, CH);
    }

    @Override
    public double calcularSalario() {
        return getCH()*valorPorHora;
    }
}
