/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.aula03;

/**
 *
 * @author andre
 */
public class AULA03 {

    public static void main(String[] args) {
        
    }
    
    public static int maior(int... numeros){
        int maior=numeros[0];
        for(int i=0; i<numeros.length; i++){
            if(numeros[i] > maior) maior = numeros[i];
        }
        
        return maior;
    }
    
    public static int procuraMaiorValor(int numeros[]){
        int maior=numeros[0];
        for(int i=0; i<numeros.length; i++){
            if(numeros[i] > maior) maior = numeros[i];
        }
        
        return maior;
    }
    
    public static void printDiagonalPrincipal(int matriz[][]){
        for(int i=0; i<matriz.length; i++){
            System.out.printf("%d ", matriz[i][i]);
        }
    }
}
