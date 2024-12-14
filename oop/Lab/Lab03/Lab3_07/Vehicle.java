public class Vehicle {
   int wheel;


    public void run(){
        Engine engine= new Engine();
        Wheel wheel= new Wheel();

        engine.run();
        wheel.run();
        
    }
    
}