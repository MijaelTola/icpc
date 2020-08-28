import java.util.Scanner;

public class P1566 {

    static int v[] = new int[1010];
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        int casos = 1;
        while(in.hasNext()) {
            int n = in.nextInt();
            if(n == 0) break;
            for (int i = 0; i < n; ++i) {
                v[i] = in.nextInt();
            }
            
            System.out.printf("Case %d:\n", casos++);
            int q = in.nextInt();
            
            while(q > 0) {
                q--;
                int x = in.nextInt();
                int disMin = 100000;
                int respuesta = 0;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if(i == j) continue;
                        int sum = v[i] + v[j];
                        int distancia = Math.abs(sum - x);
                        if(distancia < disMin) {
                            disMin = distancia;
                            respuesta = sum;
                        }
                    
                    }
                }
            System.out.printf("Closest sum to %d is %d.\n", x, respuesta);
            }
        }
    }
}

