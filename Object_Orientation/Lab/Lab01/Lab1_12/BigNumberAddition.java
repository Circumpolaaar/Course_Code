import java.math.BigInteger;
import java.util.Scanner;

public class BigNumberAddition {
    public static void main(String[] args) {
       //char[] a = new char[100];
       //char[] b = new char[100];
        Scanner scanner = new Scanner(System.in);
        
        String a = scanner.nextLine();
        String b = scanner.nextLine();

        char[] arr1 = a.toCharArray(); // 获取一个字符数组
        char[] arr2 = b.toCharArray(); // 获取一个字符数组
        
        int[] sum = new int[100];

        //把arr1倒着添加到结果串
        int i;
        int j=0;
        for (i=arr1.length-1;i>=0;i--) {
            sum[j]=(arr1[i]-'0');
            //System.out.print(sum[j]);
            j++;
        }
         int length1=j;
        
        
        //把arr2倒着加上去,大于10的进位
        j=0;
        int temp=0;
        for (i=arr2.length-1;i>=0;i--) {
            temp=sum[j]+(arr2[i]-'0');
            //System.out.println(sum[j]+"+"+(arr2[i]-'0')+"="+temp);     
                sum[j]=temp%10;
                sum[j+1]+=temp/10;
           
            j++;
            temp=0;
        }
        int length2=j;
        int max=length1>length2?length1:length2;
        //倒着输出
        for (i=max-1;i>=0;i--) {
            //if (sum[i] != 0) {
                System.out.print(sum[i]);
            //}
            

        }
    }
}