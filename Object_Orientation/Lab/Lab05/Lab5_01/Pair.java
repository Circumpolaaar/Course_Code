public class Pair<T1, T2> {
    private T1 t1;
    private T2 blg;

    public Pair(T1 t1,T2 blg){
        this.t1 = t1;
        this.blg = blg;
    }

    public T1 getT1(){
        return this.t1;
    }
    public T2 getT2(){
        return this.blg;
    }

    public void setT1(T1 t1){
        this.t1 = t1;
    }
    public void setT2(T2 blg){
        this.blg = blg;
    }


    public void swap(){
        
        if (t1 instanceof Parent && blg instanceof Parent) {
        
        
        T1 champion=t1;
        t1=(T1)blg;
        blg=(T2)champion;
        }
    }

    public String toString() {
        return "Pair{"+"T1="+this.t1+", T2="+this.blg+'}';
    }
}
