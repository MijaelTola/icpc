import java.util.*;

public class P1880 {
    
    static Scanner leer = new Scanner(System.in);

    public static void main(String [] args) {
        
        int casos = leer.nextInt();
        
        for (int i = 0; i < casos; i++) {
            int n = leer.nextInt();
            int [] megusta = new int[n + 10];

            for (int j = 0; j < n; j++) 
                megusta[j] = leer.nextInt();   
            
            Boolean seAman = false;

            for (int j = 0; j < n; ++j) {
                int a = j + 1;
                int b = megusta[j];
                int c = megusta[b - 1];
                int d = megusta[c - 1];

                if(d == a && a != b && b != c && a != c) seAman = true; 
            }

            if(seAman == true) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
                
        }
    }
}
