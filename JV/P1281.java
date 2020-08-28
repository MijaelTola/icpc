import java.util.Scanner;

public class P1281 {
    
    // 24
    // 2 2 2 3
    public static void solve(int x) {
        Boolean flag = true;
        for (int i = 1; i * i <= x; i++) {
            if(x % i == 0) {
                if(!flag)System.out.print(" ");
                flag = false;
                System.out.print(i);
            }
        }

        for (int i = (int)Math.sqrt(x); i >= 1; i--) {
            if(x % i == 0 && i != x / i) {
                if(!flag)System.out.print(" ");
                flag = false;
                System.out.print(x / i);
            }
        }
        System.out.println();
    }
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);

        while(in.hasNext()) {
            int n = in.nextInt();
            System.out.printf("Divisores de %d: ", n);
            solve(n);
        }
    }
}

