public class test {

    public static String strscat(String... args) {
        StringBuilder result = new StringBuilder();
        for (String arg : args) {
            result.append(arg);
        }
        return result.toString();
    }

    public static void main(String[] args) {
       
        System.out.println(strscat(new String[]{"a", "b"}));  

        
    }
}
