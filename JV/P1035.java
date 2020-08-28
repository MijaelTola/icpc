import java.util.Scanner;

public class P1035 {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);

        while(in.hasNext()) {
            String x = in.nextLine();
            if(x.equals("#")) break;
            x = x.replace("%","%25");
            x = x.replace(" ","%20");
            x = x.replace("!","%21");
            x = x.replace("$","%24");
            x = x.replace("(","%28");
            x = x.replace(")","%29");
            x = x.replace("*","%2a");
            System.out.println(x);
        }
    }
}
