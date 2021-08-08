
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in Actual solution is at the top
 */
public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    B(in, out);
    out.close();
  }

 
  static int x, y; 
  static int gcd(int a, int b) {
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
  
    else
    {
        int g = gcd(b, a % b);
        int x1 = x, y1 = y;
        x = y1;
        y = x1 - (a / b) * y1;
        return g;
    }
}

  static boolean can(int a, int b, int c) {
    int t = gcd(a,b);
    int xx =  x * c;
    int yy =  y * c;
    int aa = xx / a;
    int bb = yy / b;
    int xxx = xx + aa * a;
    int yyy = yy + bb * b;
    return c % t == 0 && xxx >= 0 && yyy >= 0;
  }

  static void B(InputReader in, PrintWriter out) {
    int n = in.nextInt();
    int v[] = new int[n + 10];

    for (int i = 0; i < n; ++i)
      v[i] = in.nextInt();

    int q = in.nextInt();

    for (int qq = 0; qq < q; ++qq) {
      int x = in.nextInt();
      boolean flag = false;
      for (int i = 0; i < n; ++i) {
        flag |= x % v[i] == 0;
        for (int j = i; j < n; ++j) {
          if(v[i] + v[j] <= x) {
            flag |= can(v[i], v[j], x);
          }
        }
      }

      if (flag)
        out.println("YES");
      else
        out.println("NO");
    }

  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }

  }
}
