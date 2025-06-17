package ex001.application;

import ex001.model.entities.MinhaClasse;
import ex001.model.interfaces.MinhaInterface;

public class App {
    public static void main(String[] args) {
        String minhaFrase = "Aluno";        
        MinhaInterface myInterface = new MinhaClasse();
        myInterface.setFrase(minhaFrase);
        myInterface.concatenar(" de Programação OO");
        System.out.printf("Frase: %s, Tam: %d", myInterface.getFrase(), myInterface.tamanho());
    }
}
