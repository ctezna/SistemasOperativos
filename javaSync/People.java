import java.util.Random;

public class People implements Runnable{
    private Garden garden;
    public People(Garden garden){
        this.garden = garden;
    }
    public void run(){
        while(true){
            Random r = new Random();

            try{
                garden.enter();
                Thread.sleep(Math.abs(r.nextInt()) % 3000 + 1000);
                garden.exit();
                Thread.sleep(Math.abs(r.nextInt()) % 3000 + 1000);
            } catch (InterruptedException ie){

            }
        }
    }
}