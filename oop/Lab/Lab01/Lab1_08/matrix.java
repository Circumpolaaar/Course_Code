import java.util.Scanner;

public class matrix {
    public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int i, j;
    int k = 0 ;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            System.out.print(k+1 + " ");
            k++;
        }
        System.out.println();
    }
    scanner.close(); 
    }
}