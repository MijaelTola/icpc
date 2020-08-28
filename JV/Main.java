import java.util.Scanner;

public class Main {
    public static void main(String [] args) {
        Scanner  in = new Scanner(System.in);

        System.out.println("Introducir A:");
        int a = in.nextInt();
        System.out.println("Introducir B:");
        int b = in.nextInt();
        System.out.println("El resultado es: " + (a + b));
    }
}

