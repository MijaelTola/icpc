import java.util.Scanner;

public class string2 {
    
    static String [] v = new String [110];
        
    public static void Swap(int i, int j) {
        String aux = v[i];
        v[i] = v[j];
        v[j] = aux;
    }
    
    public static Boolean verificar(String a, String b) {
        
        for (int i = 0; i < Math.min(a.length(), b.length()); i++) {
            if(a.charAt(i) > b.charAt(i)) return true;
            if(a.charAt(i) < b.charAt(i)) return false;
        }
        return a.length() > b.length();
    }

    public static void sort(int n) {
        
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
               if(verificar(v[i],v[j])) Swap(i,j); 
            }
        }
    }
    public static void main(String [] args) {
   
        Scanner in = new Scanner(System.in);
        
        int n = in.nextInt();
        
        for (int i = 0; i < n; ++i) {
            v[i] = in.next();
        }
        
        sort(n);
    
        System.out.println("########################");
        for (int i = 0; i < n; ++i) {
            System.out.println(v[i]);
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        /*String s = in.nextLine();
        String t = in.nextLine();
        
        //if(s.compareTo(t) == 0)
            //System.out.println("Son Iguales");
            //
        String z = s.concat(t);
        System.out.println(z);*/
        /*
            X = ABC
            Y = DEF
            Z = ABCDEF
            Z = X + Y
            Z = X.concat(Y);
         * */
    }
}

