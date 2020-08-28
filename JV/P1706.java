import java.util.Scanner;

public class P1706 {
    public static void main(String [] args) {
   
        Scanner in = new Scanner(System.in);

        while(in.hasNext()) {
            
            int n = in.nextInt();
            
            Boolean ans = false;
            for (int i = 0; i < n; ++i) {
                int x = in.nextInt();
                ans |= (x == 1);
            }
            if(ans) System.out.println("HARD");
            else System.out.println("EASY");
        }
    }
}

