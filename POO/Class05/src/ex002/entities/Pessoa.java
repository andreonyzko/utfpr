package ex002.entities;
public class Pessoa {
    private String nome;
    private double altura, peso;
    
    public Pessoa(String n, double a, double p){
        nome = n;
        altura = a;
        peso = p;
    }
    
    public String getNome(){
        return nome;
    }
    
    public void setNome(String n){
       nome = n;
    }
    
    public double getAltura(){
        return altura;
    }
    
    public void setAltura(double a){
        altura = a;
    }
    
    public double getPeso(){
        return peso;
    }
    
    public void setPeso(double p){
        peso= p;
    }
}
