package Lab07_08;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;

public class Main {
    public static void main() {
        // you can call and test your method here
        try{
            copyDirectory("sourceDir", "targetDir");
        }catch(IOException e){
            e.printStackTrace();
        }
    }
    
    public static void copyDirectory(String sourceDir, String targetDir) throws IOException {
        // your implementation
        File f1=new File(sourceDir);
        File f2=new File(targetDir);
        
        if(!f2.exists()){
            f2.mkdirs();
        }
        File[] files=f1.listFiles();
        if(files!=null){
            for(File file:files) {
                if(file.isDirectory()){
                    copyDirectory(file.getAbsolutePath(),targetDir+File.separator+file.getName());
                }
                else{
                    Path sourcePath=file.toPath();
                    Path targetPath=new File(targetDir+File.separator+file.getName()).toPath();
                    Files.copy(sourcePath,targetPath,StandardCopyOption.REPLACE_EXISTING);
                }
            }
        }
    }
}
