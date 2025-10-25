

public class test {
    public static void main(String[] args) {
        Parent p1=new Parent();
        Parent p2=new Parent();
        Parent c1=new Child1();
        Parent c2=new Child2();
        //Child1 C1toP=(Child1) c1;
        //Child2 C2toP=(Child2) c2;
        Dog d=new Dog();
        Pair<Parent,Parent> pair1=new Pair<>(p1,p2);
        Pair<Parent,Parent> pair2=new Pair<>(c1,c2);
        Pair<Dog,Parent> pair3=new Pair<>(d, p2);

        System.out.println("类型相同:");
        System.out.println("交换前："+pair1.toString());
        pair1.swap();
        System.out.println("交换后："+pair1.toString());

        System.out.println("都是子类:");
        System.out.println("交换前："+pair2.toString());
        pair2.swap();
        System.out.println("交换后："+pair2.toString());

        System.out.println("类型不同:");
        System.out.println("交换前："+pair3.toString());
        pair3.swap();
        System.out.println("交换后："+pair3.toString());
    }
}
