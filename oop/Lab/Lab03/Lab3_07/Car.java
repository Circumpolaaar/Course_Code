public class Car extends Vehicle {
    public Car(){
        this.wheel=4;
    }
    public void Run(){
        System.out.println("Now the car is running.");       
        this.run();
        System.out.println("\n");
    }
}
