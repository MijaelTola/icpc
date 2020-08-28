import java.util.Scanner;
import java.util.Arrays;

public class P1310 {
    
    static int [] Etotal = new int[55];
    public static void main(String [] args) {  
        Scanner in = new Scanner(System.in);
        while(in.hasNext()) {
            int n = in.nextInt();

            int eocupado = 0;
            for (int i = 0; i < n; ++i) {
                int x = in.nextInt();
                eocupado += x;
            }

            for (int i = 0; i < n; ++i) 
                Etotal[i] = in.nextInt();
            
            Arrays.sort(Etotal, 0, n);
            
            int pos = n - 1;
            int contar = 0;
            while(eocupado > 0) {
                eocupado -= Etotal[pos];
                pos--;
                contar++;
            }
            System.out.println(contar);
        }
    }
}

