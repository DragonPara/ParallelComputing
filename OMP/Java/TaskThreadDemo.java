public class TaskThreadDemo{
    public static void main(String[] args) {
        Runnable printA = new PrintChar('a', 100);
        Runnable print100 = new PrintNum(100, 100);
        Thread a = new Thread(printA);
        Thread b = new Thread(print100);
        a.start();
        b.start();
    }
}
class PrintChar implements Runnable{
    private char charToPrint;
    private int times;
    public PrintChar(char c,int t){
        charToPrint=c;
        times=t;
    }
    @Override
    public void run(){
        for(int i = 0 ; i<times;i++){
            System.out.print(charToPrint);
        }
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