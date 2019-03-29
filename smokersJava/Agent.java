import java.util.Random;

public class Agent implements Runnable {
    private Table table;

    public Agent(Table table) {
        this.table = table;
    }

    public void run(){
        Random r = new Random();
        while(true){
            EnumSmokers smoker = EnumSmokers.NOSMOKER;
            switch(Math.abs(r.nextInt() % 3)){
                case 0:
                    smoker = EnumSmokers.NOTOBACCO;
                    break;
                case 1:
                    smoker = EnumSmokers.NOPAPER;
                    break;
                case 2:
                    smoker = EnumSmokers.NOMATCH;
                    break;
            }
            table.putIngredient(smoker);
            try {
                Thread.sleep(Math.abs(r.nextInt()) % 5000 + 1000);
            } catch(InterruptedException ie){}
            table.getSignalAgent();
            try {
                Thread.sleep(Math.abs(r.nextInt()) % 5000 + 1000);
            } catch(InterruptedException ie){}
        }
    }
}