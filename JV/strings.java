import java.util.Scanner;

public class strings {

    static int alfabeto [] = new int [30];
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        /*String x;
        System.out.println("Leer un numero:");
        int numero = in.nextInt();
        in.nextLine();
        System.out.println("Leer un cadena:");
        x = in.nextLine();
        System.out.println(x);*/    
        //String s = in.next();
        /*for (int i = 0; i < s.length(); ++i) 
            alfabeto[s.charAt(i) - 'a']++;


        for (int i = 0; i < 27; ++i) {
            char caracter = (char)(i + 'a');
            if(alfabeto[i] > 0)
                System.out.println(caracter + ": " + alfabeto[i]);
        }*/

        /*for (char i = 'a'; i <= 'z'; i++) {
            int contador = 0;
            for (int j = 0; j < s.length(); ++j) {
                if(i == s.charAt(j)) contador++;
            }
            System.out.println(i + ": " + contador);
        }*/
        //string matching
        String x,y;
        x = in.next();
        y = in.next();
        String z = x.concat(y);
        System.out.println(z);

    }
}

