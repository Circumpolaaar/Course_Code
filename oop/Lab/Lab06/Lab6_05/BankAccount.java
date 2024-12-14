package Lab6_05;

public class BankAccount {
    int balance;
    public BankAccount(int n){
        this.balance=n;
    }
    public void deposit(int money){
        this.balance+=money;
        System.out.println("存款成功，当前金额："+this.balance);
    }
    public void withdraw(int money)throws InsufficientFundsException{
        if(money<=this.balance){
            this.balance-=money;
            System.out.println("取款成功，当前金额："+this.balance);
        }
        else{
            throw new InsufficientFundsException();
        }
    }
    public static void main(String[] args) {
        BankAccount account =new BankAccount(100);
        account.deposit(100);
        try{
            account.withdraw(500);
        } catch(InsufficientFundsException e){
            System.out.println("取款失败，"+e.getMessage());
        }    
    }
}
