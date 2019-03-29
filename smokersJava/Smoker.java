import java.util.Random;

public class Smoker implements Runnable {
    private EnumSmokers smoker;
    private Table table;

    public Smoker(EnumSmokers smoker, Table table) {
        this.smoker = smoker;
        this.table = table;
    }

    public void run(){
        Random r = new Random();
        while(true){
            table.getIngredient(smoker);
            try {
                Thread.sleep(Math.abs(r.nextInt()) % 5000 + 1000);
            } catch(InterruptedException ie){}
            System.out.println("Smoker: " + smoker);
            table.putSignalAgent();
            try {
                Thread.sleep(Math.abs(r.nextInt()) % 5000 + 1000);
            } catch(InterruptedException ie){}
        }
    }
}