package Lab07_04;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.io.Serializable;

class Student implements Serializable{
    private String studentId;
    private String name;
    private double score;
    // constructor(s) and other methods ...
    public Student(String studentId,String name,double score){
        this.name=name;
        this.score=score;
        this.studentId=studentId;
    }
    
    public static void serializeIntoFile(Student[] students,String file) {
        // your implementation
        File f = new File(file);
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(f))) {
            oos.writeObject(students);
        }catch(IOException e){
            e.printStackTrace();
        }
    }
    public static Student[] deserializeFromFile(String filePath)throws ClassNotFoundException {
        // your implementation
        Student[] students=null;
        File f = new File(filePath);
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(f))) {
            students = (Student[]) ois.readObject();
            
        }catch(IOException e){
            e.printStackTrace();
        }
        return students;
    }
    public static void ser(File f,Object o)throws Exception{
          //判断目录是否存在
          if (!f.getParentFile().exists()){
              f.getParentFile().mkdirs();
          }
          //判断文件是否存在
          if (!f.exists()){
              f.createNewFile();
          }
          //创建一个字节输出流对象
          OutputStream ops=new FileOutputStream(f);
          //创建一个实现序列化的对象
          ObjectOutputStream oos=new ObjectOutputStream(ops);
          //实现序列化
          oos.writeObject(o);
          oos.close();
          ops.close();
    }

    public static void dser(File f) throws Exception{
        //创建一个字节输入流
        InputStream in=new FileInputStream(f);
        //创建一个实现反序列化的对象
        ObjectInputStream input=new ObjectInputStream(in);
        //实现反序列化
        Object obj=input.readObject();
        System.out.println(obj);
        //关闭
        input.close();
        in.close();
    }
    public String toString(){
        return this.studentId+","+this.name+","+this.score;
    }
    
}