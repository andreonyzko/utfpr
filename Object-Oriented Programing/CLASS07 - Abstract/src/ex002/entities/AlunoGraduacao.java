package ex002.entities;

public class AlunoGraduacao extends Aluno{
    private double notaTCC;

    public AlunoGraduacao(String nome, int ra, double notaDisciplinas, double notaTCC) {
        setNome(nome);
        setRa(ra);
        setNotaDisciplinas(notaDisciplinas);
        this.notaTCC = notaTCC;
    }

    public double getNotaTCC() {
        return notaTCC;
    }

    public void setNotaTCC(double notaTCC) {
        this.notaTCC = notaTCC;
    }

    public double getNotaFinal(){
        return (getNotaDisciplinas() + notaTCC) / 2;
    };
}
