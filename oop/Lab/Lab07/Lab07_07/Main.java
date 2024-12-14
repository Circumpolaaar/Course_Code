package Lab07_07;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Main {
    public static void main() {
        // you can call and test your method here
        try{
            String file1="input.txt";
            String file2="output.txt";
            copyFile(file1, file2);
        }catch(IOException e){
            e.printStackTrace();
        }
    }
    
    public static void copyFile (String sourceFile, String targetFile) throws IOException {
        // your implementation
        try(FileInputStream fis=new FileInputStream(sourceFile);
            FileOutputStream fos=new FileOutputStream(targetFile)){
            byte[] buffer = new byte[4096];
            int bytesRead;
            while ((bytesRead = fis.read(buffer)) != -1) {
                fos.write(buffer, 0, bytesRead);
            }
        }
    }
}
