public abstract class Shape {
    protected double a;
    protected double b;

    public Shape() { this(0.0, 0.0); }
    public Shape(double a, double b) {
        this.a = a;
        this.b = b;
    }

    
    abstract public double calcArea();

    
    public double getA() {
        return this.a;
    }
    public double getB() {
        return this.b;
    }

    public void setA(double a) {
        if(a >= 0){
            this.a = a;
        }else{
            this.a = 0;
        }
        
    }
    public void setB(double b) {
        if(b >= 0){
            this.b = b;
        }else{
            this.b = 0;
        }
    }
}