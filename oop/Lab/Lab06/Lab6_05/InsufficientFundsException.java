package Lab6_05;

public class InsufficientFundsException extends Exception{
    public InsufficientFundsException() {
        super("失败原因：余额不足");
    }
}
