import java.util.Scanner;

public class P1449 {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        int n,a,b;
        a = in.nextInt();
        b = in.nextInt();
        n = in.nextInt();

        int v [] = new int[n];

        for (int i = 0; i < n; ++i)
            v[i] = in.nextInt();
        
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if(a <= v[i] && v[i] <= b)
                sum += v[i];
        }
        System.out.println(sum);
    }
}

