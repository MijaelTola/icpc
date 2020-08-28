import java.util.Scanner;

public class P1340 {

    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);   
        
        /*
            12345
            12345 % 10 = 5
            12345 / 10 = 1234
            nd = numeroDigitos = 5
            5 * 10 ^ (nd - 1`)
            51234

            7 = {}
            2 3 4
            8 = {2 , 4}
            2 3 4 
         * */
        while(in.hasNext()) {
            int x = in.nextInt();
            if(x == -1) break;
            
            int numeroDigitos = (int)Math.log10(x) + 1;
            boolean esCircular = true;
            for (int i = 0; i < numeroDigitos; ++i) {
                int ulti = x % 10;
                x /= 10;
                x = ulti * (int)Math.pow(10, numeroDigitos - 1) + x;
                boolean esPrimo = true;
                for (int j = 2; j <= x / 2; ++j) {
                    if(x % j == 0) {
                        esPrimo = false;
                        break;
                    }
                }
                //esPrimo == true? el numero es primo
                //esPrimo == false? el numero no es primo
                if(!esPrimo) {
                    esCircular = false;
                    break;
                }
                //esCircular &= esprimo;
            }

            if(esCircular) 
                System.out.println("SI");
            else 
                System.out.println("NO");
            
        }
    }
}
