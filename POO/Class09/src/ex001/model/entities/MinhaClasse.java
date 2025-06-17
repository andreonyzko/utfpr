package ex001.model.entities;

import ex001.model.interfaces.MinhaInterface;

public class MinhaClasse implements MinhaInterface {
    private String frase;

    @Override
    public void concatenar(String s) {
        frase = frase.concat(s);
    }

    @Override
    public String getFrase() {
        return frase;
    }

    @Override
    public void setFrase(String frase) {
        this.frase = frase;
    }

    @Override
    public int tamanho() {
        return frase.length();
    }
    
}
