//example ThreadGroup

class exThread4 implements Runnable{

    public void run(){
        System.out.println("This is another thread: " + Thread.currentThread());
    }

    public static void main(String []args){
        ThreadGroup tg = new ThreadGroup("Thread-Group");
        Thread ex41 = new Thread(tg, new exThread4(), "exThread4-1");
        Thread ex42 = new Thread(tg, new exThread4(), "exThread4-2");
        ex41.start();
        ex42.start();
        System.out.println("This is a thread: " + Thread.currentThread());
    }
}