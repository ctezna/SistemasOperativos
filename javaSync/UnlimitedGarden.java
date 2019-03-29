public class UnlimitedGarden implements Garden{
    private int counter;
    public UnlimitedGarden(){
        counter = 0;
    }

    public synchronized void enter(){
        counter++;
    }

    public synchronized void exit(){
        counter--;
    }

    public synchronized int getCounter(){
        return counter;
    }
}