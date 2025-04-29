/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.aula05;

/**
 *
 * @author andre
 */
public class AlunoAnalise {
    Aluno alunos[];
    
    public AlunoAnalise(Aluno alunos[]){
        this.alunos = alunos;
    }
    
    public void listarAlunosPorGenero(char genero){
        for(int i=0; i < alunos.length; i++){
            if(alunos[i].genero == genero){
                System.out.printf("%s - %d - %c\n", alunos[i].nome, alunos[i].idade, alunos[i].genero);
            }
        }
    }
    
    public void listarAlunoMaisVelho(){
        int index = 0;
        for(int i=0; i < alunos.length; i++){
            if(alunos[i].idade > alunos[index].idade){
                index = i;
            }
        }
        
        System.out.printf("%s - %d - %c\n", alunos[index].nome, alunos[index].idade, alunos[index].genero);
    }
    
    public void listarAlunoMaisJovem(){
        int index = 0;
        for(int i=0; i < alunos.length; i++){
            if(alunos[i].idade < alunos[index].idade){
                index = i;
            }
        }
        
        System.out.printf("%s - %d - %c\n", alunos[index].nome, alunos[index].idade, alunos[index].genero);
    }
    
    public double getMediaIdade(){
        double media = 0, divisor=0;

        for(int i=0; i <= alunos.length; i++){
            media += alunos[i].idade;
            divisor++;
        }
        
        return (media/divisor);
    }
}
