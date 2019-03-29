public class LimitedGarden implements Garden{
    private int counter, max;

    public LimitedGarden(int max){
        counter = 0;
        this.max = max;
    }

    public synchronized void enter(){
        try {
            while (max == counter) wait();
        }catch(InterruptedException ie){}
        counter++;
    }

    public synchronized void exit(){
        if (max == counter) notify();
        counter--;
    }

    public synchronized int getCounter(){
        return counter;
    }
}