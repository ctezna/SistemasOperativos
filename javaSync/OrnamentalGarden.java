public class OrnamentalGarden {
    public static void main(String args[]){
        Garden garden = args.length == 0 ? new JardinIlimitado() : new JardinLimitado(25);

        Thread tAdmin = new Thread(new Admin(garden));

        for (int i = 0; i < 100; ++i){
            Thread t = new Thread(new People(garden));
            t.start();
        }
        tAdmin.start();
        try {
            tAdmin.join();
        }catch (InterruptedException ie){}
    }
}