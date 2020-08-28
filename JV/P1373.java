import java.util.Scanner;
public class P1373 {
    public static void main(String [] args) {

        Scanner in = new Scanner(System.in);

        String cad = in.next();

        char x = cad.charAt(0);

        int val = (int)x;
        
        if(val >= 65 && val <= (25 + (int)'A'))
            System.out.println("mayuscula");
        else 
            System.out.println("minuscula");

        if(x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U'
                || x == 'a' || x == 'e' || x == 'i' || x == 'o' 
                || x == 'u')
            System.out.println("vocal");
        else 
            System.out.println("consonante");

    }
}
