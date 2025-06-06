package ex003.application;

import ex003.entities.Aluno;
import ex003.services.AlunoAnalise;

public class App {
    public static void main(String[] args) {
        Aluno alunos[] = new Aluno[4];
        alunos[0] = new Aluno("João", 24, 'M');
        alunos[1] = new Aluno("Maria", 44, 'F');
        alunos[2] = new Aluno("Ana", 18, 'F');
        alunos[3] = new Aluno("Julia", 36, 'F');

        AlunoAnalise analise = new AlunoAnalise(alunos);
        analise.listarAlunosPorGenero('M');

        Aluno alunos2[] = new Aluno[4];
        alunos2[0] = new Aluno("João", 24, 'M');
        alunos2[1] = new Aluno("Maria", 44, 'F');
        alunos2[2] = new Aluno("Ana", 18, 'F');
        alunos2[3] = new Aluno("Julia", 36, 'F');

        AlunoAnalise analise2 = new AlunoAnalise(alunos2);
        analise2.listarAlunoMaisVelho();

            
        Aluno alunos3[] = new Aluno[4];
        alunos3[0] = new Aluno("João", 24, 'M');
        alunos3[1] = new Aluno("Maria", 44, 'F');
        alunos3[2] = new Aluno("Ana", 18, 'F');
        alunos3[3] = new Aluno("Julia", 36, 'F');

        AlunoAnalise analise3 = new AlunoAnalise(alunos3);
        analise3.listarAlunoMaisJovem();
    }  
}
