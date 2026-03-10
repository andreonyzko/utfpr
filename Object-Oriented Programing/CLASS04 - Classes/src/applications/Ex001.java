package applications;

import entities.Aluno;

public class Ex001 {
    public static void main(String[] args) {
        Aluno a1 = new Aluno();
        a1.print();

        Aluno aluno2 = new Aluno("Fulana", 'F', 20232323);
        aluno2.print();
    }
}
