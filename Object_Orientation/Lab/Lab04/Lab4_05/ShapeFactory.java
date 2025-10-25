import java.util.Random;
public class ShapeFactory {
    public Shape makeShape(ShapeType type, double a, double b){
        if(a<0||b<0){
            return null;
        }
        switch (type) {
            case Re:
                Rectangle re = new Rectangle();
                re.setA(a);re.setB(b);
                return re;
            case Rh:
                Rhombus rh = new Rhombus();
                rh.setA(a);rh.setB(b);
                return rh;
            case El:
                Ellipse el = new Ellipse();
                el.setA(a);el.setB(b);
                return el;
            default:
                return null;
        }
    }

    public Random random = new Random();
    public Shape randomNextShape(){
        ShapeType type=ShapeType.values()[random.nextInt(ShapeType.values().length)];
        double a=10*random.nextDouble();
        double b=10*random.nextDouble();
        return makeShape(type, a, b);
    }
}
