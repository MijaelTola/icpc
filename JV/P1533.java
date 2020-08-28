import java.util.Scanner;

public class P1533 {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        
        while(in.hasNext()) {
            long n,k;
            n = in.nextLong();
            k = in.nextLong();

            if(k <= (n + 1) / 2) {
                System.out.println(k * 2 - 1);
            } else {
                System.out.println(2 * (k - (n + 1) / 2));
            }
        }
    }

    //5
    //1 3 5 2 4
    //6
    //1 3 5 2 4 6
}
