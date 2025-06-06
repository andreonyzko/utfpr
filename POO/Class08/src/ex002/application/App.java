package ex002.application;

import ex002.entities.Aluno;
import ex002.entities.AlunoGraduacao;
import ex002.entities.AlunoMestrado;

public class App {
    public static void main(String[] args) {
        Aluno alunos[] = new Aluno[4];
        alunos[0] = new AlunoGraduacao("Jonas", 1234, 7.8, 10.0);
        alunos[1] = new AlunoGraduacao("Maria", 5522, 9.8, 7.0);
        alunos[2] = new AlunoMestrado("Pedro", 3311, 7.5, 8.5, 0);
        alunos[3] = new AlunoMestrado("Patricia", 7098, 9.5, 9.5, 3);
        
        for (int i=0; i<alunos.length; i++){
            System.out.printf("Aluno(a): %s, Nota Final: %.2f\n", alunos[i].getNome(), alunos[i].getNotaFinal());
        }
    }
}
