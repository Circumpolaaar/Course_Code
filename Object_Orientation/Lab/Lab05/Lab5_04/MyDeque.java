import java.util.LinkedList;

public class MyDeque<T>{
    private final LinkedList<T> elements;
    
    public MyDeque(){
        this.elements=new LinkedList<>();
    }
    
    public void addFirst(T element){
        //int n=elements.size();
        elements.addFirst(element);
    }
    public void addLast(T element){
        elements.addLast(element);
    }
    
    public T removeFirst(){
        if (elements.isEmpty()){
            return null;
        }
        return elements.removeFirst();
    }
    public T removeLast(){
        if (elements.isEmpty()){
            return null;
        }
        return elements.removeLast();
    }
    public boolean isEmpty(){
        return elements.isEmpty();
    }
    public void printDeque(){
        System.out.println(elements);
    }
}