import java.util.concurrent.*;
public class ExecutorDemo{
    public static void main(String[] args) {
        ExecutorService executor  = Executors.newFixedThreadPool(100);
        executor.execute(new Runnable(){
            public void run(){
                System.out.println("ok");
            }
        });
        Runnable a = new PrintNum(1,2);
        executor.execute(a);
        executor.shutdown();
    }
}
class PrintNum implements Runnable{
    private int intToPrint;
    private int times;
    public PrintNum(int i,int t){
        intToPrint=i;
        times=t;
    }
    @Override
    public void run(){
        for(int i = 0 ; i <times;i++)
        System.out.print(intToPrint);
    }
}