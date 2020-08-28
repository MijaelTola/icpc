import java.util.Scanner;
public class P1444 {

    public static int contar(int n) {
        int respuesta = 0;
        int contador = 0;
        while(n > 0) {
            if(n % 2 != 0) contador++;
            else {
                respuesta += contador / 2;
                contador = 0;
            }
            n/=2;
        }
        if(contador > 0) respuesta += contador / 2;
        return respuesta;
    }
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        
        int t = in.nextInt();
        for (int i = 0; i < t; ++i) {
            int n = in.nextInt();
            System.out.println(contar(n));
        }
    }
}
