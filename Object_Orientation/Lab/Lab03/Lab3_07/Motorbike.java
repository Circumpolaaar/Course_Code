public class Motorbike extends Vehicle {
    String driver;
    String passenger;
    public Motorbike(){
        this.wheel=2;
    }
    public void setPeople(String driver,String passenger){
        this.driver=driver;
        this.passenger=passenger;
    }
    public void Run(){
        System.out.println("Now the motorbike is running.");       
        this.run();
        System.out.println("\n");
    }
   
}
