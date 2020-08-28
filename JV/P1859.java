import java.util.*;

public class P1859 {
    static Scanner leer = new Scanner(System.in);

    static int in() {
        return leer.nextInt();
    }

    public static void main(String [] args) {

        int t = in();

        for (int casos = 0; casos < t; ++casos) {

            int a[] = new int[7];
            for (int i = 0; i < 6; ++i)
                a[i] = in();

            int c = a[0] * 2 + 1;
            int r = 0;
            int i;
            for (i = 0; i < Math.min(a[1],a[5]); i++, c+=2) 
                r+=c;
            for (c--; i < Math.max(a[1],a[5]); i++) 
                r+=c;
            for (c--; i < a[1]+a[2]; i++, c-=2) 
                r+=c;

            System.out.println(r);
        }
    }
}
