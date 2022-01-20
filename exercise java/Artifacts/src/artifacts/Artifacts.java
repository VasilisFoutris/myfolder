/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package artifacts;

import artifacts.enums.Condition;
import artifacts.enums.Material;
import artifacts.enums.Movement;
import artifacts.enums.Technique;
import java.util.Arrays;
import java.util.Random;

/**
 *
 *
 */
public class Artifacts {
    
    private final int index;
    private final String creator;
    private final int year;
    
    public Artifacts(int index, String creator, int year) {
        this.index = index;
        this.creator = creator;
        this.year = year;
        
        System.out.println("Creating an instance of Artifacts");
    }
    
    public void getInfo() {
        System.out.println("Creator: " + creator + " - Year: " + year);
    }
    
    public void getIndex() {
        System.out.println("Index: " + index);
    }
    
    public static void auction(Artifacts[] artifacts, Movement movement, Condition condition) {
        Arrays.stream(artifacts).forEach(a -> {
            a.getIndex();
            
            if(a.getClass().equals(Paintings.class)) {
                ((Paintings)a).getInfo();
            } else {
                ((Sculptures)a).getInfo();
            }
            
            if(a.getClass().equals(Paintings.class)) {
                System.out.println("The painting evaluates to " + ((Paintings)a).evaluate(movement, condition));
            } else {
                System.out.println("The sculpture evaluates to " + ((Sculptures)a).evaluate(movement, condition));
            }
        });
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        int n = Integer.parseInt(args[0]);
        
        Movement movement = Movement.valueOf(args[1]);
        
        Condition condition = Condition.valueOf(args[2]);
        
        Artifacts[] artifacts = new Artifacts[n];
        
        Random random = new Random();
        
        Movement[] movements = Movement.values();
        Condition[] conditions = Condition.values();
        Material[] materials = Material.values();
        Technique[] techniques = Technique.values();
        
        for(int i = 0; i < artifacts.length; i++) {
            if(random.nextInt() % 2 == 0)
                artifacts[i] = new Paintings(i, "Creator" + i, random.nextInt(2022), movements[random.nextInt(movements.length)], 
                        conditions[random.nextInt(conditions.length)], random.nextDouble() * 100 % 20, random.nextDouble() * 100 % 20, 
                        techniques[random.nextInt(techniques.length)]);
            else
                artifacts[i] = new Sculptures(i, "Creator" + i, random.nextInt(2022), movements[random.nextInt(movements.length)], 
                        conditions[random.nextInt(conditions.length)], random.nextDouble() * 100 % 20, materials[random.nextInt(materials.length)]);
        }
        
        System.out.println("\n\n\n\n\n");
        
        Artifacts.auction(artifacts, movement, condition);
        
    }
    
}
