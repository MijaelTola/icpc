import java.util.Scanner;

public class P1468 {
    
    static int primos[] = new int[100010];
    public static void criba() {
        
        for (int i = 2; i * i < 100010; ++i) {
            int c = i;
            if(primos[i] != 0) continue;
            while(c < 100010) {
                primos[c]++;
                c += i;
            }
        }
    }
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        criba();
        while(in.hasNext()) {
            int a = in.nextInt();
            int b = in.nextInt();
            int mx = 0;
            int numero = 0;
            for (int i = a; i <= b; ++i) {
                //System.out.println(i + ": " + primos[i]);
                if(primos[i] >= mx) {
                    mx = primos[i];
                    numero = i;
                }
            }
System.out.println(numero + " tiene " + primos[numero] + " divisores");
        }
    }
} 
