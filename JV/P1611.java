import java.util.Scanner;

public class P1611 {

    static int v[] = new int [110];
    static int visitado[] = new int[110];
    public static void main(String [] args) {
   
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        for (int i = 0; i < n; ++i)
            v[i] = in.nextInt();

        int pos = 0; //boton 0 esta encendido inicialmente

        while(pos != m) {
            if(visitado[pos] == 1) break;
            visitado[pos] = 1;
            pos = v[pos];
        }

        if(pos == m) System.out.println("SI");
        else System.out.println("NO");
    }
}

