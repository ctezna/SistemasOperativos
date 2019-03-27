//example isAlive

class exThread5 implements Runnable{

    public void run(){
        System.out.println("This is another thread: " + Thread.currentThread());
    }

    public static void main(String []args){
        ThreadGroup tg = new ThreadGroup("Thread-Group");
        Thread ex51 = new Thread(tg, new exThread5(), "exThread5-1");
        Thread ex52 = new Thread(tg, new exThread5(), "exThread5-2");
        ex51.start();
        ex52.start();
        try{
            System.out.println("ThreadGroup Actives: " + tg.activeCount());
            System.out.println("Is Alive: " + ex51.isAlive());
            System.out.println("This is a thread: " + Thread.currentThread());
            ex51.join();
            System.out.println("Is Alive: " + ex51.isAlive());
            System.out.println("ThreadGroup Actives: " + tg.activeCount());
        } catch (InterruptedException ie){

        }
    }
}