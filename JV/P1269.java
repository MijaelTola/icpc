import java.util.Scanner;

public class P1269 {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);   

        while (in.hasNext()) {
            int n1,d1,n2,d2;
            n1 = in.nextInt();
            d1 = in.nextInt();
            n2 = in.nextInt();
            d2 = in.nextInt();

            if(n1 == d1 && d1 == n2 && n2 == d2 && d2 == 0) 
                break;

            if(n1 * d2 == n2 * d1) 
                System.out.println("=");
            else 
                System.out.println("!=");
        }
    }
}
