import java.util.*;
import java.math.*;

public class P{
	static int lim = 1000000;
	static boolean Primes[] = new boolean[lim + 10];
	static ArrayList<Integer> P = new ArrayList<Integer>();
	
	public static void primes() {
		for (int i = 2; i <= lim; i++) {
			if (!Primes[i]) {
				for (int j = i + i; j <= lim; j+=i)
					Primes[j] = true;
			}
		}
		P.add(2);
		for (int i = 3; i <= lim; i += 2)if(!Primes[i])P.add(i);
	}
	
	public static long _pow(long base, long p) {
		if (p == 0)return 1;
		if (p == 1)return base;
		long res = _pow(base, p >> 1);
		res *= res;
		if (p % 2 == 1)res *=base;
		return res;
	}
	
	public static long sumDiv(long n) {
		int pos = 0, PF = P.get(pos); long ans = 1;
		while (PF * PF <= n) {
			int power = 0;while (n  % PF == 0){ n /= PF; power++;}
			ans *= (_pow(PF, power + 1) - 1) / (PF - 1);
			if (pos + 1 >= P.size())break;
			PF = P.get(++pos);
		}
		if (n != 1) ans *= (_pow(n , 2) - 1) / (n - 1);
		// ans *= ((ll)_pow(n , 2) - 1) / (n - 1);
		return ans;
	}
		
	public static void main(String [] args){
		primes();
		long l, r;
		Scanner sc = new Scanner(System.in);
		l = sc.nextLong();
		r = sc.nextLong();
		
		long ans = 0;
	while(l <= r){
		
		BigInteger NN = BigInteger.valueOf(l);
		if (NN.isProbablePrime(50)) {
			NN = NN.pow(2);
			NN = NN.subtract(BigInteger.ONE);
			NN = NN.divide(BigInteger.valueOf(l - 1));
			ans += NN.longValue();
		} else {
			ans += sumDiv(l);
		}
		l++;
	}
	System.out.println(ans);	
	

	}
}
