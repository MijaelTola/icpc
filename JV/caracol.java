import java.util.Scanner;

public class caracol {

    static int dy[] = {1,0,-1,0};
    static int dx[] = {0,1,0,-1};
    static int c[][] = new int [101][101];
    static int n,m;
        
    public static Boolean verificar(int x,int y) {
        return x >= 0 && x < n && y >= 0 && y < m && c[x][y] == 0;
    }
    
    public static int digitos(int x) {
        int sum = 0;
        while(x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    public static void main(String [] args) {
   
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = n;
        int x = 0, y = 0;
        //x maneja las fila
        //y maneja las columnas
        c[0][0] = 1;
        int pos = 0;
        int dig = 2;
        for (int i = 0; i < n * m - 1; ++i) {
            int u = x + dx[pos];
            int v = y + dy[pos];
            if(verificar(u,v)) {
                c[u][v] = digitos(dig);
                x = u;
                y = v;
            } else {
                pos = (pos + 1) % 4;
                u = x + dx[pos];
                v = y + dy[pos];
                c[u][v] = digitos(dig);   
                x = u;
                y = v;
            }
            dig++;
        }
        //IMPRIMIR LA MATRIZ
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; j++) {
                System.out.print(c[i][j]);
                if(j + 1 < m)System.out.print(" ");
            }
            System.out.println();
        }
    }
}

