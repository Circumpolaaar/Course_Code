public class test {
    public static void main(String[] args) {
        Car car = new Car();
        Tank tank = new Tank();
        Motorbike motorbike = new Motorbike();
        car.Run();
        tank.Run();
        motorbike.Run();

        Person sister=new Person("Amy",18);
        Person brother=new Person("Andy",20);

       
        motorbike.setPeople(brother.name,sister.name);
        System.out.println(motorbike.driver+" is driving and "+motorbike.passenger+" is on the motorbike.");
        sister.say();

    }
    
}
