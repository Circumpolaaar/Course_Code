package Lab6_07;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class readFile {
    public static void main(String[] args) {
        //正常文件
        //String filePath = "text.txt"; 
        //不存在文件
        String filePath = "1.txt"; 
        
        try(BufferedReader r=new BufferedReader(new FileReader(".\\"+filePath))){
            String line;
            while ((line = r.readLine()) != null) {
                System.out.println(line);
            }
        }catch(FileNotFoundException e){
            
            System.out.println("文件未找到:"+filePath);
        }catch(IOException e){
            System.out.println("读取错误");
        }
    }
}
