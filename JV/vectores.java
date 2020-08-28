import java.util.Scanner;
import java.util.Arrays;

public class vectores {

    static int v[] = new int[110000];
    static int c[] = new int[110000];

    static void swap(int x, int y) {
        int a = v[x];
        v[x] = v[y];
        v[y] = a;
    }

    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);   
        //0 1 2 3 4 5 6 7 8 9  | 10
        //0 1 2 3 .... 98 99 100
        
        int n = in.nextInt();
        
        for (int i = 0; i < n; ++i) {
            int x = in.nextInt();
            v[i] = x;
        }
        
        //Arrays.sort(v,1,n - 1);


        //METODO BURBUJA
        /*
        for (int i = 0; i < n; ++i) {
            //buscando menores de v[i] que este a la derecha de i
            for (int j = i + 1; j < n; ++j) {
                if(v[i] > v[j]) swap(i,j);
            }
        }
 */
        //COUNTING SORT
        
        for (int i = 0; i < n; ++i) {
            int x = v[i];
            c[x]++;
        }
        int pos = 0;
        for (int i = 0; i < 100000; ++i) {
            if(c[i] > 0) {
                for (int j = 0; j < c[i]; ++j) {
                    v[pos] = i;
                    pos++;
                }
            }
        }
        for (int i = 0; i < n; ++i) 
            System.out.print(v[i] + " ");
        
        System.out.println();
        //creo un vector para contar
 /*       for (int i = 0; i < n; ++i) {
            int x = in.nextInt();
            v[x]++;
        }

        for (int i = 0; i < n; ++i) {
            if(v[i] > 0) {
           System.out.println("Existen "+ v[i] + " ocurrencias de " + i);
            }   
        }*/
        /*
        for (int i = 0; i < n; ++i) {
            int x = in.nextInt();
            v[i] = x;
        }

        for (int i = 0; i < n; ++i) {
            if(i + 1 < n)System.out.println(v[i] + " " + v[i + 1]);
        }*/
    }
}
