package ex001.application;

import ex001.entities.Carro;

public class App {
    public static void main(String[] args) {
        Carro carro1 = new Carro();
        carro1.setRenavam(123456789);
        carro1.setPlaca("AAA-1234");
        carro1.setCor("Preto");
        carro1.setNumeroDePortas(4);
        carro1.setPotenciaMotor(115);
        carro1.printInformacoes();
    }
}
