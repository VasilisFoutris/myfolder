/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package artifacts;

import artifacts.enums.Condition;
import artifacts.enums.Movement;

/**
 *
 *
 */
public class Masterpiece extends Artifacts {
    
    protected final Movement movement;
    protected Condition condition;
    
    public Masterpiece(int index, String creator, int year, Movement movement, Condition condition) {
        super(index, creator, year);
        this.movement = movement;
        this.condition = condition;
        
        System.out.println("Creating an instance of Masterpiece");
    }

    public void setCondition(Condition condition) {
        this.condition = condition;
    }
    
    @Override
    public void getInfo() {
        super.getInfo();
        System.out.println("Movement: " + movement + " - Condition: " + condition);
    }
    
}
