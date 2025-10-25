import java.util.Scanner;

public class Test{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入数字：");
        String input = scanner.nextLine();
        scanner.close();

        if (isUnsignedInt(input)) {
            System.out.println("是没有前导0的无符号整数.");
            if (isHuiwen(input)) {
                System.out.println("是回文数。");
            } else {
                System.out.println("不是一个回文数。");
            }
        } 
        else {
            System.out.println("不是没有前导0的无符号整数。");
        }
    }

    private static boolean isUnsignedInt(String s) {
        //判断是否为空
        if (s == null || s.isEmpty()) {
            return false;
        }

        //判断是否是一位数
        if(s.length() == 1){
            return true;
        }

        //非空的两位，判断前导零
        for (int i = 0; i < s.length(); i++) {
            //第一个就是0
            if (i == 0 && s.charAt(i) == '0') {
                return false; 
            }
            //判断非法字符
            if (!Character.isDigit(s.charAt(i))) {
                return false;
            }
        }
        return true;
    }

    private static boolean isHuiwen(String s) {
        String r = new StringBuilder(s).reverse().toString();
        return s.equals(r);
    }

}