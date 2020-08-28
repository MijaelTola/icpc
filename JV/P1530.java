import java.util.Scanner;

public class P1530 {


    public static Boolean verificar1(int x) {
        if(x == 2 || x == 3 || x == 5 || x == 7) return true;
        return false;
    }

    public static Boolean verificar2(int x) {
        if(x == 1 || x == 0) return false;
        for (int i = 2; i <= x / 2; ++i)
            if(x % i == 0) return false;
        return true;
    }
    //y = 12345
    //ans = 54321
    public static int invertir(int y) {
        int ans = 0;
        while(y > 0) {
            int mod = y % 10;
            y /= 10;
            ans = ans * 10 + mod;
        }
        return ans;
    }

    public static void solve(int x) {
        int ans = 0;
        while(x > 0) {
            int mod = x % 10;
            x /= 10;
            if(verificar2(mod)) {//verificar mod es primo
                ans = ans * 10 + mod;
            }
        }
        ans = invertir(ans); // invertimos la respuesta
        System.out.println(ans);
    }

    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);   
        int t = in.nextInt();
        for (int i = 0; i < t; ++i) {
            int n = in.nextInt();
            solve(n);
        }
    }
}
