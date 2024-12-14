package Lab07_04;



public class Main {
    public static void main(String[] args) {
        var students = new Student[10];
        students[0]=new Student("2021001", "joe", 85.5);
        students[1]=new Student("2021002", "jane", 90.0);
        String filePath="1.txt";
        Student[] readStudents=null;
        
        Student.serializeIntoFile(students, filePath);
        try{
            readStudents = Student.deserializeFromFile(filePath);
            for (Student student : readStudents) {
                if(student!=null)
                    System.out.println(student);
            }
        }catch(ClassNotFoundException e){
            e.printStackTrace();
        }
        
    }
}