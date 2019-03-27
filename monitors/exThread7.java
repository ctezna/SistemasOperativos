//example interrupted

class exThread7 implements Runnable{

    public exThread7(){
    }


    public void run(){
        Thread t = Thread.currentThread();
        while (true){
            System.out.println("This is another thread: " + t);
            if (t.isInterrupted()) break;
        }
        System.out.println("Good bye world");
    }

    public static void main(String []args){
        ThreadGroup tg = new ThreadGroup("Thread-Group");
        Thread ex71 = new Thread(tg, new exThread7(), "exThread7-1");
        ex71.start();
        try{
            Thread.currentThread().sleep(30);
            ex71.interrupt();
        } catch (InterruptedException ie){

        }
    }
}