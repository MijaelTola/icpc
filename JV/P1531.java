import java.util.Scanner;
public class P1531 {
    
    static int n,x,contador;
    public static void ascender(int veces) {
        for (int i = 0; i < veces && contador < n; ++i) {
            System.out.print(x++);
            if(contador + 1 < n) 
                System.out.print(" ");
            contador++;
        }
        
    }
    public static void descender(int veces) {
        for (int i = 0; i < veces && contador < n; ++i) {
            System.out.print(x--);
            if(contador + 1 < n)
                System.out.print(" ");
            contador++;
        }
    }

    public static void solve() {
        contador = 0;
        int repetir = 1;
        while(contador < n) {
            if(repetir % 2 != 0) ascender(repetir);
            else descender(repetir);
            repetir++;
        }
        System.out.println();
    }
    public static void main(String [] args) {
        
        Scanner in = new Scanner(System.in);

        int t = in.nextInt();
        
        for (int i = 0; i < t; ++i) {
            n = in.nextInt();
            x = in.nextInt();
            solve();
        }
    }
}
