import java.util.Scanner;

public class P1294 {

    static int v[] = new int[1010];
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int k = 0; k < t; ++k) {
            int n,a,b;
            n = in.nextInt();
            a = in.nextInt();
            b = in.nextInt();

            for (int i = 0; i < n; ++i) {
                v[i] = in.nextInt();
            }

            for (int i = 1; i < n; ++i) 
                v[i] += v[i - 1];
                
            if(a > 0) System.out.println(v[b] - v[a - 1]);
            else System.out.println(v[b]);
       }    
    }
}

