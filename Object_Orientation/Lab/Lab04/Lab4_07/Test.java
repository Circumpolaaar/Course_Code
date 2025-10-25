public class Test {
    public static void main(String[] args) {
        Outer.method().show();
        //用类名调用method(),得是静态方法
    }
}