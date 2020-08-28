import java.util.Scanner;

public class P1576 {

    static int v [] = new int[2 * 365];
    public static void main(String [] args) {

        Scanner in = new Scanner(System.in);
        while(in.hasNext()) {
            int n = in.nextInt();

            for (int i = 0; i < n; ++i)
                v[i] = in.nextInt();

            for (int i = 0; i < n; ++i) 
                v[i + n] = v[i];

            int respuesta = 360;
            for (int i = 0; i < n; ++i) {
                int sum = 0;
                for (int j = i; j < i + n; j++) {
                    sum += v[j];// una persona A
                    int rest = 360 - sum; // a la persona B
                    respuesta = Math.min(respuesta, Math.abs(sum - rest));
                }
            }

            System.out.println(respuesta);

        }
    }
}

