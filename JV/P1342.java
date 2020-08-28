import java.util.Scanner;
public class P1342 {

    public static void main(String [] args) {
        

        Scanner in = new Scanner(System.in);
        //(A + B) % m = (A % m + B % m)
       
        int t = in.nextInt();

        for (int j = 0; j < t; ++j) {
            int n = in.nextInt();
            int m = in.nextInt();
            int a = 1;
            int b = 0;
            int c = -1;
            for (int i = 0; i < n; ++i) {
                c = (a % m + b % m) % m;
                a = b % m;
                b = c % m;
            }
            System.out.println(c % m);
        }

    }
} 
