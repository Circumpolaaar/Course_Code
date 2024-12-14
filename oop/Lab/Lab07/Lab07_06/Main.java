package Lab07_06;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Main {
    public static void main() {
        // you can call and test your method here
        try{
            String file1="input.txt";
            String file2="output.txt";
            addLineNo(file1, file2);
        }catch(IOException e){
            e.printStackTrace();
        }
    }
    
    public static void addLineNo(String inputPath, String outputPath) throws IOException {
        // your implementation
        int i=1;
        try(BufferedReader r=new BufferedReader(new FileReader(inputPath));
            BufferedWriter w=new BufferedWriter(new FileWriter(outputPath))){
            String line;
            while ((line=r.readLine())!=null){
                String s=i+" "+line;
                w.write(s);
                w.newLine();
                i++;
            }
        }
    }
}
