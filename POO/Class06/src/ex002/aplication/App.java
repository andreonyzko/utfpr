package ex002.aplication;

import ex002.entities.Aluno;

public class App {
    public static void main(String[] args) {
        Aluno aluno1 = new Aluno();
        aluno1.setMatricula(12345667);
        aluno1.setNome("Fulano");
        aluno1.setIdade(18);
        aluno1.printDados();

        Aluno aluno2 = new Aluno();
        aluno2.setMatricula(9990001);
        aluno2.setNome("Beltrano");
        aluno2.setIdade(22);
        aluno2.printDados();
    }
}
