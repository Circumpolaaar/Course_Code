package Lab07_05;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static void main() {
        // you can call and test your method here
        try{
            String file1="input.txt";
            String file2="output.txt";
            removeComments(file1, file2);
        }catch(IOException e){
            e.printStackTrace();
        }
    }
    
    public static void removeComments(String inputPath, String outputPath) throws IOException {
        // your implementation
        String singleLineCommentFromStartPattern = "^//.*";
        String singleLineCommentNotFromStartPattern = "(?<!^)//.*";

        Pattern patternFromStart = Pattern.compile(singleLineCommentFromStartPattern, Pattern.MULTILINE);
        Pattern patternNotFromStart = Pattern.compile(singleLineCommentNotFromStartPattern, Pattern.MULTILINE);

        StringBuilder content = new StringBuilder();
        try(BufferedReader r=new BufferedReader(new FileReader(inputPath))) {
            String line;
            while ((line=r.readLine())!=null){
                content.append(line).append(System.lineSeparator());
            }
        }
        Matcher matcherFromStart = patternFromStart.matcher(content);
        String uncommentedContent = matcherFromStart.replaceAll("");

        Matcher matcherNotFromStart = patternNotFromStart.matcher(uncommentedContent);
        uncommentedContent = matcherNotFromStart.replaceAll("");

        try(BufferedWriter w=new BufferedWriter(new FileWriter(outputPath))){
            w.write(uncommentedContent);
        }
    }
}
