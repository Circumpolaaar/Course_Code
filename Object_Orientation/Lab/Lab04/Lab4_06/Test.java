
public class Test {
    public static void main(String[] args) {
        //引用类型 oi = new 外部类().new 内部类();
        Outer.Inner oi = new Outer().new Inner();
        oi.show();
    }
}