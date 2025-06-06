package ex004.application;

import ex004.services.Financeiro;
import ex004.services.Lancamento;

public class App {
    public static void main(String[] args) {
        int Receber = 1, Pagar = 0;
        Financeiro financeiro = new Financeiro();
        Lancamento lanc1 = new Lancamento(Receber, "Salario", 1000.99);
        Lancamento lanc2 = new Lancamento(Pagar, "Luz", 250.56);
        Lancamento lanc3 = new Lancamento(Pagar, "Água", 180.19);
        financeiro.processarLancamento(lanc1);
        financeiro.processarLancamento(lanc2);
        financeiro.processarLancamento(lanc3);
        financeiro.printSaldo();

        Financeiro financeiro2 = new Financeiro();
        Lancamento lanc4 = new Lancamento(Receber, "Salario", 1000.99);
        Lancamento lanc5 = new Lancamento(Receber, "Megasena", 22250.56);
        Lancamento lanc6 = new Lancamento(Receber, "Bingo", 1800.19);
        financeiro2.processarLancamento(lanc4);
        financeiro2.processarLancamento(lanc5);
        financeiro2.processarLancamento(lanc6);
        financeiro2.printSaldo();

        Financeiro financeiro3 = new Financeiro();
        Lancamento lanc7 = new Lancamento(Pagar, "Funcionário", 1500.99);
        Lancamento lanc8 = new Lancamento(Pagar, "Luz", 250.56);
        Lancamento lanc9 = new Lancamento(Pagar, "Água", 180.19);
        financeiro3.processarLancamento(lanc7);
        financeiro3.processarLancamento(lanc8);
        financeiro3.processarLancamento(lanc9);
        financeiro3.printSaldo();

        Financeiro financeiro4 = new Financeiro();
        Lancamento lanc10 = new Lancamento(Receber, "Ganhei", 1000.99999);
        Lancamento lanc11 = new Lancamento(Pagar, "Perdi", 1000.99999);
        financeiro4.processarLancamento(lanc10);
        financeiro4.processarLancamento(lanc11);
        financeiro4.printSaldo();
    }
}
