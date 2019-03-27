//example extends thread

class exThread2 extends Thread{

    public exThread2() {
        super("exThread2");
    }

    public void run(){
        System.out.println("This is another thread: " + Thread.currentThread());
    }

    public static void main(String []args){
        exThread2 ex2 = new exThread2();
        ex2.start();
        System.out.println("This is a thread: " + Thread.currentThread());
    }
}