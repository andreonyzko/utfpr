package ex002.application;

import ex002.entities.Pessoa;

public class App {
    public static void main(String[] args) {	
        Pessoa p1 = new Pessoa("fulano", 1.80, 80);
        p1.setNome("ciclano");
        p1.setAltura(1.60);
        p1.setPeso(60.0);
        System.out.println(p1.getNome());
        System.out.println(p1.getAltura());
        System.out.println(p1.getPeso());

        Pessoa p2 = new Pessoa("fulano", 1.80, 80);
        p2.setNome("ciclano");
        p2.setAltura(1.60);
        p2.setPeso(60.0);
        System.out.println(p2.getNome());
        System.out.println(p2.getAltura());
        System.out.println(p2.getPeso());
    }
}
