import java.util.Scanner;

public class problemaB{
    public static void main(String [] args){
        Scanner in = new Scanner(System.in);

        while(in.hasNext()){
            String s = in.nextLine();
            int  ans = 0;
            for (int i = 0; i < s.length(); i++){
                if(s.charAt(i) == ' ') continue;
                ans += (i + 1) * (s.charAt(i) - 'A');
            }
            System.out.println(ans);
        }
    }
}
