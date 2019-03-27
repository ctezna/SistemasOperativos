//example runnable

class exThread3 implements Runnable{

    public void run(){
        System.out.println("This is another thread: " + Thread.currentThread());
    }

    public static void main(String []args){
        Thread ex31 = new Thread(new exThread3(), "exThread3-1");
        Thread ex32 = new Thread(new exThread3(), "exThread3-2");
        ex31.start();
        ex32.start();
        System.out.println("This is a thread: " + Thread.currentThread());
    }
}