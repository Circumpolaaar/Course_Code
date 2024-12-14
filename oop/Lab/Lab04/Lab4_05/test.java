import java.util.ArrayList;
import java.util.List;

public class test {
    public static void main(String[] args) {
        ShapeFactory f = new ShapeFactory();
        List<Shape> shapes = new ArrayList<>();



        for (int i = 0; i < 5; i++) {
            Shape shape=f.randomNextShape();
            shapes.add(shape);
        }

        for (Shape shape : shapes) {
            System.out.printf("The area is %.2f%n",shape.calcArea());
        }
    }
    
}
