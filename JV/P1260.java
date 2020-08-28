import java.util.Scanner;

public class P1260 {
   // a  b
    //12 8 
    public static int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    
    public static long  sumar(long a, int b) {
        long c = a * b;
        return c;
    }

    public static void restar(int x,int y) {
        System.out.println(x - y);
    }

    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);   
            int a,b;
            a = in.nextInt();
            b = in.nextInt();
            long c = sumar(a,b);
            System.out.println(c);
            //`int t = in.nextInt();
        //gcd(a,b) = gcd(b, a % b)
        //b == 0 gcd(a, b) = a
        /*for (int i = 0; i < t; ++i) {
            int a,b;
            a = in.nextInt();
            b = in.nextInt();
            int x = gcd(a,b);
            while(b > 0) {
                int f = a % b;
                a = b;
                b = f;
            }
            System.out.println(a);
        }*/
    }
}
