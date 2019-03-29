public class Table {
    private EnumSmokers next;
    private EnumAgent signalAgent;

    public Table(){
        next = EnumSmokers.NOSMOKER;
        signalAgent = EnumAgent.NOAGENT;
    }
    
    public synchronized void putIngredient(EnumSmokers smoker){
        next = smoker;
        notify();
    }

    public synchronized void getIngredient(EnumSmokers smoker){
        try{
            while (next != smoker) wait();
        } catch(InterruptedException ie){}
        next = EnumSmokers.NOSMOKER;
    }

    public synchronized void getSignalAgent(){
        try {
            while (signalAgent == EnumAgent.NOAGENT) wait();
        } catch (InterruptedException ie){}
        signalAgent = EnumAgent.NOAGENT;
    }

    public synchronized void putSignalAgent(){
        signalAgent = EnumAgent.AGENT;
        notify();
    }

}