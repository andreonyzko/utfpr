package ex003.model.entities;

public class FuncionarioClass {
    private String name;
    private double CH;

    public FuncionarioClass(String name, double CH){
        this.name = name;
        this.CH = CH;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getCH() {
        return CH;
    }

    public void setCH(double CH) {
        this.CH = CH;
    }
}
