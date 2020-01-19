import java.util.concurrent.*;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
public class AccountWithoutSync{
    public static Account account = new Account();
    public static void main(String[] args) {
        ExecutorService executor= Executors.newFixedThreadPool(100);
        for(int i = 0 ; i<100;i++)
        executor.execute(new AddAPennyTask());
        executor.shutdown();
        while(!executor.isTerminated()){
        }
        System.out.println("What's the balance : "+account.balance);
    }
    private static class AddAPennyTask implements Runnable{
        public void run(){
            account.deposit(1);
        }
    }
    public static class Account{
        private int balance= 0;
        public int getBanlanced(){
            return balance;
        }
        public  void deposit(int amount){
            int newBalance  = balance+amount;
            try {
                Thread.sleep(5);
            } catch (InterruptedException e) {}
            balance = newBalance;
        }
    }
}