import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Sol {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		while(sc.hasNext()) {
			String s=sc.nextLine();
			System.out.println(calc(s));
		}
	}
	static int calc(String s) {
		int c=0;
		for(int i=0;i<s.length();i++)
			if(s.charAt(i)!=' ')
				c+=(s.charAt(i)-'A')*(i+1);
		return c;
	}
}
