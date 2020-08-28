import java.util.Scanner;

public class P1338 {
    
    static int v[] = new int[1000100];
    static int primos[] = new int[1000100];
    static int respuesta[] = new int[1000100];
    static int sz = 0, pos;
    public static void criba() {
        for (int i = 2; i * i < 1000100; ++i) {
            for (int j = i + i; j < 1000100; j += i) {
                v[j] = 1;
            }
        }

        for (int i = 2; i < 1000100; i++) {
            if(v[i] == 0) {
                primos[sz] = i;
                sz++;
            }
        }
    }

    public static int [] factoresPrimos(int n) {
        int x [] = new int [1000100];
        int index = 0;
        int pA = primos[0];
        pos = 0;
        //hallar los factores primos de n
        while(n > 1 && index < 1000100) {
            while(n % pA == 0) {
                x[pA]++;
                n /= pA;
            }
            index++;
            pA = primos[index];
        }
        return x;
    }
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        criba();
    
        
        while(in. hasNext()) {
            int n = in.nextInt();
            if(n == -1) break;
            respuesta = factoresPrimos(n);
            System.out.print(n + " = ");
            Boolean flag = true;
            for (int i = 0; i < 1000010; ++i) {
                if(respuesta[i] > 0) {
                    if(!flag) System.out.print("*");
                    flag = false;
                    System.out.print(i);
                    if(respuesta[i] > 1) {
                        System.out.print("^" +respuesta[i]);
                    }
                }
            }
            System.out.println();
        }
    }
}

