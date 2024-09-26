package jp.ac.ait.k23023;

public class Weapon extends Equipment{

    private int atk;
    public Weapon(String name, int atk){
        super(name);
        this.atk = atk;
    }
    public Weapon(){
        super("武器");
        this.atk = 0;
    }

    public int getAtk(){
        return this.atk;
    }

    public void setAtk(int atk) {
        this.atk = atk;
    }
}
