import java.util.Scanner;

public class P1522 {

    public static int hallarUltimoDigito(int x) {
        if(x == 1 || x == 0) return 1;
        if(x == 2) return 2;
        if(x == 3) return 6;
        if(x == 4) return 4;
        return 0;
    }
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; ++i) {
            int x= in.nextInt();
            System.out.println(hallarUltimoDigito(x));
        }
    }
}
