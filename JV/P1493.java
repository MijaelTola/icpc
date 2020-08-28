import java.util.Scanner;

public class P1493 {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);   
        
        String t = in.nextLine();
        String s = in.nextLine();

        t = t.toLowerCase();
        s = s.toLowerCase();
        
        for (int i = 0; i < t.length() - s.length(); ++i) {
            String subCadena = t.substring(i, i + s.length());
            if(s.equals(subCadena))
                System.out.println(i);
        }
        
    }
}
