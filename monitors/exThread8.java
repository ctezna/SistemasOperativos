//example interrupted

class exThread8 implements Runnable{

    public exThread8(){
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
        Thread ex81 = new Thread(tg, new exThread8(), "exThread8-1");
        ex81.start();
        try{
            Thread.currentThread().sleep(30);
            ex81.interrupt();
        } catch (InterruptedException ie){

        }
    }
}