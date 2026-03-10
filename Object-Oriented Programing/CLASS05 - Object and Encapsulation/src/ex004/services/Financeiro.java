package ex004.services;
public class Financeiro {
    float saldo;
    
    public Financeiro(){
        saldo = 0;
    }
    
    public void processarLancamento(Lancamento lanc){
        if(lanc.getTipo() == 1){
            saldo += lanc.getValor();
        } else{
            saldo -= lanc.getValor();
        }
        
        System.out.printf("Lançamento: %s - %s - %.2f\n", lanc.getTipo() == 1? "Receber" : "Pagar", lanc.getDescricao(), lanc.getValor());
    }
    
    public void printSaldo(){
        System.out.printf("Saldo = %.2f\n", saldo);
    }
}