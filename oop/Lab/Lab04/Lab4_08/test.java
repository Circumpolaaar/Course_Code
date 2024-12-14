
public class test {
    public static void main(String[] args) {
        int size =10;
        ShapeSequence outer=new ShapeSequence(size);
        ShapeSequence Test=new ShapeSequence(size);
        interFace<Shape> inner=outer.iterator();
        interFace<Shape> o1=Test.iterator();
        interFace<Shape> o2=outer.iterator();
        
        //测试
        //add()
        //outer的size为10，超过后将不再添加
        for(int i=0;i<3;i++){
            Rectangle re = new Rectangle();
            re.setA(i);re.setB(i);
            outer.add(re);
        }
        for(int i=3;i<7;i++){
            Ellipse el = new Ellipse();
            el.setA(i);el.setB(i);
            outer.add(el);
        }
        for(int i=7;i<20;i++){
            Rhombus rh = new Rhombus();
            rh.setA(i);rh.setB(10-i);
            outer.add(rh);
        }
        
        System.out.println("创建了一个大小为"+size+"的容器");
        //toString()
        //返回字符串形式
        System.out.println("容器中的元素是"+outer.toString());
        
        //使用current()和moveNext()
        //输出前五个shape
        System.out.println("测试current()和moveNext()：");
        System.out.println("前五个元素是：");
        for(int i=0;i<5;i++){
            Shape s = inner.current();
            System.out.printf("now is %s whose a is %.1f, b is %.1f, area is %.1f\n", s, s.getA(), s.getB(), s.calcArea());
            inner.moveNext();
        }
        //测试equals()
        System.out.println("测试equals()：");
        //和o1不同外部类
        System.out.println("当二者不同外部类：");
        if(o1.equals(inner)){
            System.out.println("here are two same iterators");
        }
        else{
            System.out.println("here are two different iterators");
        }
        //和o2同一外部类不同位置
        System.out.println("当二者同一外部类不同位置：");
        if(o2.equals(inner)){
            System.out.println("here are two same iterators");
        }
        else{
            System.out.println("here are two different iterators");
        }
        //和o2同一外部类同一位置
        System.out.println("当二者同一外部类同一位置：");
        //把o2迭代到7，上文中inner到5
        for(int i=0;i<5;i++){
            o2.moveNext();
        }
        if(o2.equals(inner)){
            System.out.println("here are two same iterators");
        }
        else{
            System.out.println("here are two different iterators");
        }


        System.out.println("测试结束，好梦");
    }
}
