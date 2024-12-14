public class TestPerson {
    public static void main(String[] args) {
        Person p1 = new Person("Emma",-1,"female");
        p1.setAge(19);
        p1.getAge();
        p1.showAge();
        p1.work();

        Person p2 = new Person("Kiran",17,"female");
        p2.setAge(18);
        p2.getAge();
        p2.showAge();
        p2.work();
    }
}
