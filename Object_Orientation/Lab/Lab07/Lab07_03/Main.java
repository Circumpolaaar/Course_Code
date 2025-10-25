package Lab07_03;



public class Main {
    public static void main(String[] args) {
        var students = new Student[10];
        students[0]=new Student("2021001", "joe", 85.5);
        students[1]=new Student("2021002", "jane", 90.0);
        String filePath="1.txt";
        
        Student.writeIntoFile(filePath,students);
        var stus = new Student[10];
        stus=Student.readFromFile(filePath);
        for(Student student:stus){
            System.out.println(student);
        }
    }
}