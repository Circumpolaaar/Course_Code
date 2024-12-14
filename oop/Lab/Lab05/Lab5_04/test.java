public class test {
    public static void main(String[] args) {
        MyDeque<Integer> deque=new MyDeque<>();
        deque.addFirst(2);
        deque.addFirst(1);
        deque.addLast(4);
        deque.addLast(5);
        deque.printDeque();
        deque.removeFirst();
        deque.removeLast();
        deque.printDeque();

        MyDeque<String> deque1=new MyDeque<>();
        deque1.addFirst("A");
        deque1.addFirst("J");
        deque1.addLast("V");
        deque1.addLast("A");
        deque1.printDeque();
        deque1.removeFirst();
        deque1.removeLast();
        deque1.printDeque();
    }
}
