import java.util.*;
import java.math.BigInteger;
import java.math.BigDecimal;
import java.text.DecimalFormat;
public class zombie{
    
    static BigInteger mone = new BigInteger("-1");
    static BigInteger one = new BigInteger("1");
    static BigInteger zero = new BigInteger("0");
    static BigInteger [][] dp = new BigInteger[25][410];
    static int [] d = new int[4];
    static int x,y,z,h;
    static boolean sign;
    static void memset(){
        for (int i = 0; i < 25; i++)
            for (int j = 0; j < 410; ++j)
                    dp[i][j] = mone;
    }
    public static BigInteger f(int pos, int sum){
        if(pos == x){
            if(sign){
                if(sum+z >= h) return one; 
            }else if(sum-z>= h) return one;
            return zero;
        }

        if(dp[pos][sum] != mone) return dp[pos][sum];
        BigInteger ans = new BigInteger("0");
        for (int i = 1; i <= y; i++) 
            ans = ans.add(f(pos+1,sum+i));
        return dp[pos][sum] = ans;
    }
    public static void main(String [] arg){
        Scanner in = new Scanner(System.in);
        int t;
        t = in.nextInt();
        for (int k = 1; k<=t; k++){
            int s;
            h = in.nextInt();
            s = in.nextInt();
            double ans = 0.0;
            for (int i = 0; i < s; i++){
                memset();
                String r = new String("");
                r = in.next();
                d[0] = d[1] = d[2] = d[3] = 0;
                int pos = 0;
                for (int j = 0; j < r.length(); j++){
                    if(Character.isDigit(r.charAt(j)))
                        d[pos] = d[pos]*10+(r.charAt(j)-'0');
                    else{
                        pos++;
                        if(r.charAt(j) == '+' || r.charAt(j) == '-'){
                            if(r.charAt(j) == '+') d[pos] = 1;
                            pos++;
                        }
                    }
                }
                x = d[0]; y = d[1]; 
                if(d[2] == 1) sign = true;
                else sign = false;
                z = d[3];
                BigInteger favo = f(0,0);
                BigDecimal fav = new BigDecimal(favo);
                BigInteger X = new BigInteger(String.valueOf(x));
                BigInteger Y = new BigInteger(String.valueOf(y));
                BigDecimal total = new BigDecimal(Y.pow(x));
                BigDecimal prob = fav.divide(total,20,BigDecimal.ROUND_HALF_UP);
                double cur = prob.doubleValue();
                if(cur > ans) ans = cur;
            }
            DecimalFormat six = new DecimalFormat("#0.000000");
            System.out.println("Case #"+k+": "+six.format(ans));
        }
    }
}
