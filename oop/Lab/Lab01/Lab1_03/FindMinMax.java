public class FindMinMax {
    public static void main(String[] args) {
        double temp, max, min;
        double d1 = 1, d2 = -9.9, d3 = 96.9;
        
        //temp为d1 d2中较大者
        temp = d1 > d2 ? d1 : d2;
        max = temp > d3 ? temp : d3;

        temp = d1 < d2 ? d1 : d2;
        min = temp < d3 ? temp : d3;
        
        System.out.println("max = " + max);
        System.out.println("min = " + min);
    }
}