import java.util.Scanner;

public class Main {

    public static int numeroAB(String V[], int t, String cad) {
        int ab = 0;
        for (int i = 0; i < t; i++) {
            if (V[i].equals(cad)) {
                ab++;
            }
        }

        return ab;
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner leer = new Scanner(System.in);

        while(leer.hasNext()){
            String nn = leer.nextLine();
            leer.nextLine();
            int n = Integer.parseInt(nn);
            for (int i = 0; i < n; i++) {
                String cad = leer.nextLine();
                int tam = cad.length();
                String V[] = new String[tam];
                for (int j = 0; j < tam; j++) {
                    V[j] = cad.substring(j, j + 1);
                }
                int a = 0, b = 0;
                int marI = 1, marF = 0;

                a = a + numeroAB(V, tam, "A");
                b = b + numeroAB(V, tam, "B");

                for (int j = 1; j < tam - 1; j++) {
                    if (V[j].equals(".")) {
                        marI = j;
                        for (int j2 = j; j2 < tam - 1; j2++) {
                            if (V[j2].equals(".")) {
                                marF = j2;
                            } else
                                j2 = tam;
                        }

                        if (V[marI - 1].equals("A") && V[marF + 1].equals("A")) {
                            a = a + (marF - marI) + 1;
                        }
                        if (V[marI - 1].equals("B") && V[marF + 1].equals("B")) {
                            b = b + (marF - marI) + 1;
                        }

                    }
                }

                System.out.println(a + " " + b);
            } 
        }

    }
}
