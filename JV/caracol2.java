import java.util.Scanner;

public class caracol2 {

    static int [][]c = new int[110][110];

    static int dx[] = {0,1,0,-1};
    static int dy[] = {1,0,-1,0};
    static int n,m;
    
    public static Boolean verificar(int x,int y) {
        return x >= 0 && y >= 0 && x < n && y < m && c[x][y] == 0;
    }

    public static int sumarDigitos(int x) {
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
            
        int x = 0, y = 0, pos = 0;
        int contador = 2;
        c[0][0] = 1;
        for (int i = 0; i < n * m - 1; ++i) {
            int u = x + dx[pos];
            int v = y + dy[pos];
            if(verificar(u,v)) {
                x = u; y = v;
                c[x][y] = sumarDigitos(contador++);
            } else {
                pos = (pos + 1) % 4;
                x = x + dx[pos];
                y = y + dy[pos];
                c[x][y] = sumarDigitos(contador++);
            }
        }
    
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                System.out.print(c[i][j]);
                if(j + 1 < m) System.out.print(" ");
            }
            System.out.println();
        }
    }
}

