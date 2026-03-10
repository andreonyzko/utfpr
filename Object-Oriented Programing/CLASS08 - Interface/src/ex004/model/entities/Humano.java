package ex004.model.entities;

import ex004.model.interfaces.CapazDeAssobiar;

public class Humano implements CapazDeAssobiar {        
    public void assobiar(String assobio){
        System.out.println(assobio);
    }        
}
