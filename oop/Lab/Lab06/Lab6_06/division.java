package Lab6_06;

import java.util.InputMismatchException;
import java.util.Scanner;

public class division {

    public static void main(String[] args) throws InputMismatchException,ArithmeticException{
        Scanner scanner = new Scanner(System.in);
        int a,b;
        try{
            a=scanner.nextInt();
            b=scanner.nextInt();

            int result=a/b;
            System.out.println(a+"/"+b+"="+result);
        }catch(InputMismatchException e){
            System.out.println("输入的不是整数");
        }catch(ArithmeticException e){
            System.out.println("除数不能为0");
        }finally{
            System.out.println("程序结束");
            scanner.close();
        }
    }
    
}
