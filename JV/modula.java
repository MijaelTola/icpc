import java.util.Scanner;
import java.math.BigInteger;

public class modula{
	public static void main(String [] arg){
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		for (int i = 0; i < n; i++){
			BigInteger A = in.nextBigInteger();
			BigInteger M = in.nextBigInteger();
			System.out.println(A.mod(M));
		}
	}
}
