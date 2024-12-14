public class Tank extends Vehicle {
    public Tank(){
        this.wheel=0;
    }
    public void Run(){
        System.out.println("Now the tank is running.");       
        this.run();
        System.out.println("\n");
    }
}
