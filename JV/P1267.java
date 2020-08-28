import java.util.Scanner;

public class P1267{

    //PROCEDIMIENTOS
    public static void resolverImprimir(int gradas) {
        int solucion = 2 * gradas + 1;
        System.out.println(solucion);
    }

    //FUNCION
    public static int solucionar(int gradas) {
        int solucion = 2 * gradas + 1;
        return solucion;
    }

    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);   
        
        while(in.hasNext()) {
            int n = in.nextInt();
            if(n == -1) break;
            //LLAMANDO AL PROCEDIMIENTO
            //resolverImprimir(n);
            int respuesta = solucionar(n);
            System.out.println(respuesta);
        }
    }
}
