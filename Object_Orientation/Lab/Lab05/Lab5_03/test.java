public class test {

    public static void main(String[] args){
        Box<Integer> box1=new Box<>(3);
        Box<Double> box2=new Box<>(2.5);


        Number maxValue=Box.compareBoxes(box1,box2);
        
        System.out.println("max="+maxValue);
    }
}