
public class indexOut {
    public static void main(String[] args) {
        int array[] =new int[20];
        int index=30;
        try{
            System.out.println(array[index]);
        } catch(ArrayIndexOutOfBoundsException e){
            System.out.println("数组越界:"+e.getMessage());
        
        }
    }
}
