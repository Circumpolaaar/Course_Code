package Lab6_08;

import java.io.IOException;

public class Main {
    public static void start() throws IOException, RuntimeException {
        throw new RuntimeException("Unable to Start");
    }

    public static void main(String[] args) {
        try {
            start();
        } catch (Exception ex) {
            ex.printStackTrace();
        } /*catch (RuntimeException re) {
            re.printStackTrace();
            //RuntimeException是Exception子类
            //上一个catch已经抛出了RuntimeException
            //这个catch不可及
        }*/
    }
}