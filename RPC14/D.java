import java.util.*;
import java.math.*;

public class D{
	static BigInteger [][] M = new BigInteger[2][2];
	static void solve(){
		Matriz i = new Matriz(BigInteger.ONE,BigInteger.ZERO,BigInteger.ZERO,BigInteger.ONE);
		Queue<Matriz> q = new LinkedList<Matriz>();
		q.push(i);
	}
	public static void main(String [] carajo){
		
	}
}

 class Matriz{
	public BigInteger a,b,c,d;
	public String ans;
	public Matriz(BigInteger x,BigInteger y, BigInteger w, BigInteger z){
		a = x; b = y; c = w; d = z;
		ans = "";
	}
	
	public void Mult1(){
		b = a.add(b);
		d = c.add(d);
	}
	
	public void Mult2(){
		a = a.add(b);
		c = c.add(d);
	}
}
