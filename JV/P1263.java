import java.util.Scanner;

public class P1263 {

    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        while(in.hasNext()) {
            int der = in.nextInt();
            int x = in.nextInt();
            int izq = 1;
            int contador = 0;
            while(izq < der) {
                int mitad = (der + izq) / 2;
                if(mitad < x) izq = mitad + 1;
                if(mitad > x) der = mitad - 1;
                if(mitad == x) break;
                contador++;
            }
            System.out.println(contador + 1);
        }
    }
}
