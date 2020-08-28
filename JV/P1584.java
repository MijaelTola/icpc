import java.util.Scanner;

public class P1584 {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        //PROBLEMA E 1584
        while(in.hasNext()) {

            int n = in.nextInt();

            int mn = 100000; //minimo
            int mx = -1;//maximo
            for (int i = 0; i < n; ++i) {
                int a = in.nextInt();
                mn = Math.min(mn,a);
                mx = Math.max(mx,a);
            }

            System.out.println(mx - mn);
        }

    }
}
