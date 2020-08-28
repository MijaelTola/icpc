import java.util.Scanner;
public class P12602 {
    public static void main(String [] args) {

        Scanner in = new Scanner(System.in);

        int t = in.nextInt();

        for (int i = 0; i < t; ++i) {
            int a,b;
            a = in.nextInt();
            b = in.nextInt();
            //ALGORITMO DE EUCLIDES
            //mcd(a,b)
            int mcd = Math.min(a,b);
            while(a % mcd != 0 || b % mcd != 0) mcd--;
            
            int mcd2 = 1;

            for (int i = 1; i <= Math.min(a,b); i++) 
                if(a % i == 0 && b % i == 0) 
                    mcd2 = i;

            System.out.println(mcd);
        }
    }
}

/*
 *
4           8
3 / 2        3  / 2


12 / 8       24 /  16

6  / 4       12 / 8

3  / 2       6 / 4

             3 / 2



 *
 * */
