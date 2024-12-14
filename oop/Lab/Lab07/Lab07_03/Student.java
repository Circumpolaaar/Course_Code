package Lab07_03;

import java.util.ArrayList;
import java.util.List;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

class Student {
    private String studentId;
    private String name;
    private double score;
    // constructor(s) and other methods ...
    public Student(String studentId,String name,double score){
        this.name=name;
        this.score=score;
        this.studentId=studentId;
    }
    public static void writeIntoFile(String file,Student[] students) {
        // your implementation
        try(BufferedWriter w=new BufferedWriter(new FileWriter(file))){
            for(Student student:students){
                if(student!=null){
                    w.write(student.studentId+","+student.name+","+student.score);
                    w.newLine();
                }
                
            }
        }catch(IOException e){
            e.printStackTrace();
        }
    }
    public static Student[] readFromFile(String filePath) {
        // your implementation
        List<Student> list=new ArrayList<Student>();
        try(BufferedReader r=new BufferedReader(new FileReader(filePath))){
            String info;
            while((info=r.readLine())!=null){
                String[] parts=info.split(",");
                String studentId=parts[0];
                String name=parts[1];
                double score=Double.parseDouble(parts[2]);
                Student s=new Student(studentId, name, score);
                list.add(s);
            }
        }catch(IOException e){
            e.printStackTrace();
        }
        return list.toArray(new Student[0]);
    }
    public String toString(){
        return this.studentId+","+this.name+","+this.score;
    }
}