import java.util.Scanner;

public class P1144 {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);

        int t = in.nextInt();

        for (int casos = 0; casos < t; ++casos) {
            int x = in.nextInt();
            int izq = -1;
            int der = -1;
            for (int i = x + 1; i <= x + 300; ++i) {
                boolean esprimo = true;
                for (int j = 2; j <= i / 2; ++j) 
                    if(i % j == 0) {
                        esprimo = false;
                        break;
                    }

                if(esprimo) {
                    der = i;
                    break;
                }
            }

            for (int i = x - 1; i >= Math.max(0, x - 300); i--) {
                boolean esprimo = true;
                for (int j = 2; j <= i / 2; ++j) 
                    if(i % j == 0) {
                        esprimo = false;
                        break;
                    }
                if(esprimo) {
                    izq = i;
                    break;
                }
            }
            System.out.println(izq + der);
        }
    }
}
