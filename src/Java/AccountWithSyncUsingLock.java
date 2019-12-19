import java.util.concurrent.*;
import java.util.concurrent.locks.*;
import java.util.Date;
public class AccountWithSyncUsingLock{
    public static Account account = new Account();
    public static void main(String[] args) {
        ExecutorService executor = Executors.newFixedThreadPool(100);
        Date t1 = new Date();
        for(int i = 0; i<100;i++){
            executor.execute(new ADDAPennyTask());
        }
        executor.shutdown();//don't forget it
        while(!executor.isTerminated()){}
        Date t2 = new Date();
        System.out.println("The balance is : " + account.getBalance());
        System.out.println(t2.getTime()-t1.getTime());
    }
    public static class ADDAPennyTask implements Runnable{
        public void run(){
            account.deposit(1);
        }
    }
    public static class Account{
        private static Lock lock = new ReentrantLock();
        private int balance = 0;
        public int getBalance(){
            return balance;
        }
        public void deposit(int amount){
            lock.lock();
            try {
                int newBalance = balance+amount;
                Thread.sleep(5);
                balance = newBalance;
            } catch (Exception e) {
            }
            finally{
                lock.unlock();
            }
        }
    }
}
