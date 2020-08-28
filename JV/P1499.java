import java.util.Scanner;

public class P1499 {

    static int [] v = new int [110];
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();

        for (int i = 0; i < n; ++i) 
            v[i] = in.nextInt();

        int pos = 0;

        //array sea estrictamente creciente
        //array sea constante
        //array sea estrictamente decreciente
        while(pos < n && v[pos] < v[pos + 1]) pos++;
        while(pos < n && v[pos] == v[pos + 1]) pos++;
        while(pos < n && v[pos] > v[pos + 1]) pos++;
        if(pos == n) System.out.println("SI");
        else System.out.println("NO");
    }
}

