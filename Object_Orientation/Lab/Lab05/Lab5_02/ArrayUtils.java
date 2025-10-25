public class ArrayUtils {
    public static <E> void printArray( E[]array ){           
         for( E e :array){
            if (e instanceof Object[]){
                printArray((Object[])e);
            }
            else{
               System.out.println(e); 
            }
        }
         System.out.println();
    }
    
}