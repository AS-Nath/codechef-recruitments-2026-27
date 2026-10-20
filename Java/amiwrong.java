import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double a = sc.nextDouble();
        double b = sc.nextDouble();
        double c = sc.nextDouble();

        if (Math.round((a + b) * 1000) / 1000.0 == c) {
            System.out.println("YES");
        }
        else {
            System.out.println("NO");
        }

        sc.close();
    }
}