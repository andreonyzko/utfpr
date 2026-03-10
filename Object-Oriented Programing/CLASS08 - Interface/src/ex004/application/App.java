package ex004.application;

import ex004.model.entities.Humano;
import ex004.model.interfaces.CapazDeAssobiar;

public class App {
    public static void main(String[] args) {
        CapazDeAssobiar geronimo = new Humano();
        geronimo.assobiar("Fiu Fiu!");

        Humano pedro = new Humano();
        pedro.assobiar("Fuuuuuu!");
    }
}
