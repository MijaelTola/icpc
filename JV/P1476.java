import java.util.Scanner;
import java.util.Arrays;

public class P1476 {

    static int v[] = new int[1010];
    static int contar[] = new int[100010];
    static int a[] = new int[1010];
    static int b[] = new int[1010];
    static Scanner in = new Scanner(System.in);
    
    public static void swap(int i, int j) {
        int x = v[i];
        v[i] = v[j];
        v[j] = x;

    }
    public static void Sort(int n) {
        //BURBUJA
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if(v[j] < v[i]) {
                    swap(i,j);
                }
            }
        }

    }
    
    public static void CountingSort(int n) {
        //contando las ocurrencias de un numero x
        for (int i = 0; i < n; ++i) {
            int x = v[i];
            contar[x]++;
        }
        int pos = 0;
        for (int i = 0; i < 100010; ++i) {
            if(contar[i] == 0) continue;
            int ocurrencias = contar[i];
            
            for (int j = 0; j < ocurrencias; ++j) {
                v[pos] = i;
                pos++;
            }
        }
        
    }

    //public static void MergeSort()
    public static void imprimir(int n) {
        for (int i = 0; i < n; ++i) {
            System.out.println(v[i]);
        }
    }
    
    public static void Solucion1() {
        int n,m;
        n = in.nextInt(); //TAMANO DE MI VECTOR A
        m = in.nextInt(); //TAMANO DE MI VECTOR B
        for (int i = 0; i < n; ++i)
            a[i] = in.nextInt();

        for (int i = 0; i < m; ++i)
            b[i] = in.nextInt();
        
        int sz = 0;
        //UNIENDO MIS VECTORES A,B EN V
        for (int i = 0; i < n; ++i) {
            v[sz] = a[i];
            sz++;
        }

        for (int i = 0; i < m; ++i) {
            v[sz] = b[i];
            sz++;
        }
        //CountingSort(sz);
        Arrays.sort(v,0, sz);
        imprimir(sz);
    }

    public static void main(String [] args) {
        Solucion1();
/*
        int n = in.nextInt();

        for (int i = 0; i <n; ++i) {
            v[i] = in.nextInt();
        }

        CountingSort(n);
        imprimir(n);*/
    }
}

