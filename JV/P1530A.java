import java.util.Scanner;
public class P1530A {
    

    public static Boolean esPrimo(int digito) {
       return (digito == 2 || digito == 3 || digito == 5 || digito == 7);
    }

    public static int invertir(int numero) {
        int ans = 0;
        while(numero > 0) {
            ans = ans * 10 + numero % 10;
            numero /= 10;
        }
        return ans;
    }
    public static void resolver(int n) {
        
        int ans = 0;
        // n = 12345
        // ans = 5
        // ans = 532
        while(n > 0) {
            int mod = n % 10;
            if(esPrimo(mod)) ans = ans * 10 + mod;
            n /= 10;
        }

        ans = invertir(ans);
        
        System.out.println(ans);
    }

    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);

        int t = in.nextInt();

        for (int i = 0; i < t; ++i) {
            int n = in.nextInt();
            resolver(n);
        }
    }
}
