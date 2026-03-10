package ex001.application;

import ex001.entities.Aluno;

public class App {
    public static void main(String[] args) {
        Aluno a1 = new Aluno();
        a1.print();

        Aluno aluno2 = new Aluno("Fulana", 'F', 20232323);
        aluno2.print();

        Aluno aluno3 = new Aluno("Ciclano da Silva", 34);
        aluno3.print();
    }
}
