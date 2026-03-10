package po23s.model.entity;

public class Ticker {
    private String name;
    private Double buy, sell;
    
    public Ticker(){}

    public Ticker(String name, Double buy, Double sell){
        this.name = name;
        this.buy = buy;
        this.sell = sell;
    }

    public String getName(){ return name; }
    public Double getBuy(){ return buy; }
    public Double getSell(){ return sell; }
    public void setName(String name){ this.name = name; }
    public void setBuy(Double buy){ this.buy = buy; }
    public void setSell(Double sell){ this.sell = sell; }
}
