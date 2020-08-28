import java.util.Scanner;

public class P1578 {


    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);


        while(in.hasNext()) {
        char c[][] = new char[11][11];
        int contar[][] = new int[11][11];
            int n,m;
            n = in.nextInt();
            m = in.nextInt();
            for (int i = 0; i < n; ++i) {
                String x; x = in.next();
                for (int j = 0; j < m; ++j) {
                    c[i][j] = x.charAt(j);
                }
            }

            int contador = 0;
            int resp = 0;
            for (int i = 0; i < n; ++i) {
                Boolean fresa = false;
                for (int j = 0; j < m; ++j) {
                    if(c[i][j] == 'S')
                        fresa = true;
                }

                if(!fresa) {
                    for (int j = 0; j < m; ++j) {
                        contar[i][j] = 1;
                    }
                }
            }

            for (int i = 0; i < m; ++i) {
                Boolean fresa = false;
                for (int j = 0; j < n; ++j) {
                    if(c[j][i] == 'S')  fresa = true;
                }
                if(!fresa) {
                    for (int j = 0; j < n; ++j)
                        contar[j][i] = 1;
                }
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    resp += contar[i][j];
                }
            }

            System.out.println(resp);
        }
    }
}

