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
        
        FileReader r=null;
        BufferedReader buffer =null;
        try {
            r=new FileReader(filePath);
            buffer = new BufferedReader(r);

            String line;
            while ((line = buffer.readLine()) != null) {
                System.out.println(line);
            }

        
        }catch(FileNotFoundException e) {
            System.out.println("检查型异常:"+e.getMessage());
        }
        catch(IOException e) {
            System.out.println("IO异常:"+e.getMessage());
        }
        finally{
            try {
                if (buffer != null)buffer.close();
                if (r != null) r.close();
            } catch (IOException e) {
                System.out.println("IO异常:"+e.getMessage());
            }
        }
        
    }
}
