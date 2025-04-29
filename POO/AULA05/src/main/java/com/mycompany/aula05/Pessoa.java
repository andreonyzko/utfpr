/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.aula05;

/**
 *
 * @author andre
 */
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
