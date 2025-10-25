public class test {
    public static void main(String[] args) {
        Ellipse el = new Ellipse();
        Rectangle re = new Rectangle();
        Rhombus rh = new Rhombus();

        el.setA(2);
        el.setB(3);

        re.setA(2);
        re.setB(3);

        rh.setA(2);
        rh.setB(3);

        double el_a = el.getA();
        double re_a = re.getA();
        double rh_a = rh.getA();

        System.out.printf("el a: %.2f%n" , el_a);
        System.out.printf("re a: %.2f%n" , re_a);
        System.out.printf("rh a: %.2f%n" , rh_a);

        System.out.printf("el area: %.2f%n" , el.calcArea());
        System.out.printf("re area: %.2f%n" , re.calcArea());
        System.out.printf("rh area: %.2f%n" , rh.calcArea());
        
        //异常
        el.setA(-1);
        el.setB(-1);
        double el_a_1 = el.getA();
        System.out.printf("el a: %.2f%n" , el_a_1);
        System.out.printf("el area: %.2f%n" , el.calcArea());
    }
    
}
