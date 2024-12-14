public class Box<T extends Number> {
    private T value;
    public Box(T value){
        this.value=value;
    }
    public T getValue(){
        return this.value;
    }
    public void setValue(T value){
        this.value=value;
    }

    public static Number compareBoxes(Box<? extends Number> b1, Box<? extends Number> b2) {
        double value1 = b1.getValue().doubleValue();
        double value2 = b2.getValue().doubleValue();
        return value1 > value2 ? value1 : value2;
    }
}
    
