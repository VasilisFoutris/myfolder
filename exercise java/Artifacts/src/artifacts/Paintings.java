/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package artifacts;

import artifacts.enums.Condition;
import artifacts.enums.Movement;
import artifacts.enums.Technique;

/**
 *
 *
 */
public class Paintings extends Masterpiece {
    
    private final double length;
    private final double width;
    private final Technique technique;

    public Paintings(int index, String creator, int year, Movement movement, Condition condition, double length, double width, Technique technique) {
        super(index, creator, year, movement, condition);
        this.length = length;
        this.width = width;
        this.technique = technique;
        
        System.out.println("Creating an instance of Paintings");
    }
    
    @Override
    public void getInfo() {
        super.getInfo();
        System.out.println("Length: " + length + " - Width: " + width + " - Technique: " + technique + " - Surface: " + length * width);
    }
    
    public boolean evaluate(Movement movement, Condition condition) {
        
        if(condition == null)
            condition = Condition.GOOD;
        
        if(this.movement == movement && this.condition == condition)
            return true;
        else if(condition == Condition.GOOD && this.condition == Condition.EXCELLENT) {
            if(this.movement == movement)
                return true;
        }
        
        return false;
    }
    
}
