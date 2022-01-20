/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package artifacts;

import artifacts.enums.Condition;
import artifacts.enums.Material;
import artifacts.enums.Movement;

/**
 *
 *
 */
public class Sculptures extends Masterpiece {
    
    private final double volume;
    private final Material material;

    public Sculptures(int index, String creator, int year, Movement movement, Condition condition, double volume, Material material) {
        super(index, creator, year, movement, condition);
        this.volume = volume;
        this.material = material;
        
        System.out.println("Creating an instance of Sculptures");
    }
    
    @Override
    public void getInfo() {
        super.getInfo();
        System.out.println("Volume: " + volume + " - Material: " + material);
    }
    
    public boolean evaluate(Movement movement, Condition condition) {
        
        if(condition == null)
            condition = Condition.EXCELLENT;
        
        if(this.movement == movement && this.condition == condition)
            return true;
        else
            return false;
    }
    
}
