package ex002.entities;

public class AlunoMestrado extends Aluno {
    private double notaDissertacao;
    private int artigosPublicados;

    public AlunoMestrado(String nome, int ra, double notaDisciplinas, double notaDissertacao, int artigosPublicados) {
        setNome(nome);
        setRa(ra);
        setNotaDisciplinas(notaDisciplinas);
        this.notaDissertacao = notaDissertacao;
        this.artigosPublicados = artigosPublicados;
    }

    public double getNotaDissertacao() {
        return notaDissertacao;
    }

    public void setNotaDissertacao(double notaDissertacao) {
        this.notaDissertacao = notaDissertacao;
    }

    public int getArtigosPublicados() {
        return artigosPublicados;
    }

    public void setArtigosPublicados(int artigosPublicados) {
        this.artigosPublicados = artigosPublicados;
    }

    public double getNotaFinal(){
        if(artigosPublicados > 0 ) return (getNotaDisciplinas() + notaDissertacao) / 2;
        return 0;
    };
}
