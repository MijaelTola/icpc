import java.util.Scanner;
public class P1180 {
     
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        int k = in.nextInt();

        for (int i = 0; i < k; ++i) {
            int n,x,t,r;
            n = in.nextInt();
            x = in.nextInt();
            t = in.nextInt();
            r = in.nextInt();
            n -= x;
            long  izq = -1;
            long der = 1000000000;
            // sum = x * (x + 1) / 2
            while(der - izq > 1) {
                long mitad = (der + izq) / 2;
                //CANTIDAD DE COLOSSUS A CREAR
                if(mitad * (mitad + 1) / 2 >= n) der = mitad;
                else izq = mitad;
            }

            long tiempo = der * r;
            if(tiempo <= t) 
                System.out.println("Construye " + der + " Colossus");
            else 
                System.out.println("GGWP");
        }
    }
}
