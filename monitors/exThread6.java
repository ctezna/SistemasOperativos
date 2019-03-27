//example setPriority

class exThread6 implements Runnable{
    private int priority;

    public exThread6(int priority){
        this.priority = priority;
    }


    public void run(){
        Thread t = Thread.currentThread();
        t.setPriority(priority);
        for(int i = 0; i < 20; ++i){
            System.out.println("This is another thread: " + Thread.currentThread());
        }
    }

    public static void main(String []args){
        ThreadGroup tg = new ThreadGroup("Thread-Group");
        Thread ex61 = new Thread(tg, new exThread6(10), "exThread6-1");
        Thread ex62 = new Thread(tg, new exThread6(1), "exThread6-2");
        ex61.start();
        ex62.start();
        try{
            ex61.join();
            ex62.join();
        } catch (InterruptedException ie){

        }
    }
}