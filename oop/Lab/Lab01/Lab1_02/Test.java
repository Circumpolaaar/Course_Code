public class Test {
    byte byteValue;
    short shortValue;
    int intValue;
    long longValue;
    boolean booleanValue;
    char charValue;
    float floatValue;
    double doubleValue;
    public static void main(String[] args) {
        Test test = new Test();
        test.PrintValue();
    }

    public void PrintValue(){
        System.out.println("byteValue: " + byteValue);
        System.out.println("shortValue: " + shortValue);
        System.out.println("intValue: " + intValue);
        System.out.println("longValue: " + longValue);
        System.out.println("booleanValue: " + booleanValue);
        System.out.println("charValue: " + charValue); 
        System.out.println("floatValue: " + floatValue);
        System.out.println("doubleValue: " + doubleValue);
        
        
    }
}
    
    

