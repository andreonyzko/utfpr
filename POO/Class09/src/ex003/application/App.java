package ex003.application;

import ex003.model.entities.Estagiario;
import ex003.model.entities.Professor;
import ex003.model.entities.Tecnico;
import ex003.model.interfaces.Funcionario;

public class App {
    public static void main(String[] args) {
        Funcionario funcs[] = {
        new Professor("Prof A", 52),
        new Professor("Prof B", 42),
        new Tecnico("Tec 1", 40),
        new Estagiario("Est 1", 6)
        };

        for (int i=0; i<funcs.length; i++){
        System.out.println(funcs[i].calcularSalario());   	
        }

        Funcionario funcs2[] = {
        new Professor("Prof A", 58.5),
        new Tecnico("Tec 1", 160),
        new Estagiario("Est 1", 80)
        };

        for (int i=0; i<funcs2.length; i++){
        System.out.println(funcs2[i].calcularSalario());   	
}
    }
}
