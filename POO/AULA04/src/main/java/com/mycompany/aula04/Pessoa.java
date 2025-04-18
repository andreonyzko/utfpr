
package com.mycompany.aula04;

public class Pessoa {
    String nome;
    double altura;
    double peso;
    double imc;
    
    public Pessoa(){
        nome= "Fulano";
        altura= 1.80;
        peso = 80;
    }
    
    public Pessoa(String nome, double altura, double peso){
        this.nome = nome;
        this.altura = altura;
        this.peso = peso;
    }
    
    public double calcularIMC(){
        return imc = peso/(altura*altura);
    }
    
    public String classificacaoIMC(){
        if(imc < 18.5) return "Magreza";
        else if(imc < 25) return "Normal";
        else if(imc < 30) return "Sobrepeso";
        else if(imc < 35) return "Obesidade grau I";
        else if(imc < 40) return "Obesidade grau II";
        else return "Obesidade grau III";
    }
}
