import java.util.Scanner;

public class P1504 {
    public static void main(String [] args) {

        Scanner in = new Scanner(System.in);

        int t = in.nextInt();

        for (int r = 0; r < t; ++r) {
            int n = in.nextInt();
            int [][] m = new int[55][55];

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    m[i][j] = in.nextInt();
                }
            }

            Boolean flag = true;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if(m[i][j] == 1) continue;
                    Boolean existe = false;
                    for (int k = 0; k < n; ++k) {
                        for (int l = 0; l < n; ++l) {
                            int suma = m[i][k] + m[l][j];
                            if(suma == m[i][j]) existe = true;
                        }
                    }
                    if(!existe) {
                        flag = false;
                        break;
                    }
                }
            }

            if(flag) System.out.println("Si");
            else System.out.println("No");
        }
    }
}

