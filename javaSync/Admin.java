import java.util.Random;

public class Admin implements Runnable{
    private Garden garden;
    public Admin(Garden garden){
        this.garden = garden;
    }
    public void run(){
        while(true){
            Random r = new Random();

            try{
                int nPeople = garden.getCounter();
                System.out.println("Clients: " + nPeople);
                Thread.sleep(Math.abs(r.nextInt()) % 5000 + 1);
            } catch (InterruptedException ie){

            }
        }
    }
}