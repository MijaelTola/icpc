import java.util.Scanner;
 
 
public class P1486 {
    static int a=1;
    static int b=0;
    static int p=0;
    public static void main(String[] args) {
        Scanner le=new Scanner(System.in);
 
        int casos=le.nextInt();
        boolean j=false;
        for (int i = 0; i < casos; i++) {
            int m = pares();
            int n = fib();
            if(!j) System.out.println(n);
            else  System.out.println(m);
            j = !j;
        }
 
    }
 
    public static int fib() {
        int c=a+b;
        a=b;
        b=c;
        return  c;
    }
 
    public static int pares() {
        p+=2;
        return p;
    }
 
}
 
