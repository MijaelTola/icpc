import java.util.*;

public class P1883 {
    
    static int n,m;

    static Scanner leer = new Scanner(System.in);
    static int in() {
        return leer.nextInt();
    }
    
    public static void main(String [] args) {
        
        LinkedList<Integer> G[];
        G = new LinkedList[10010];       
        int color[] = new int[10010];

        n = in();
        m = in();
    
        for (int i = 0; i < 10010; ++i)
            G[i] = new LinkedList<>();

        for (int i = 0; i < n - 1; ++i) {
            int x,y;
            x = in();
            y = in();
            G[x].add(y);
            G[y].add(x);
        }
        

        color[1] = 1;
        for (int i = 0; i < m; ++i) {
            int tipo, nodo;
            tipo = in();
            nodo = in();
            if(tipo == 1) {
                color[nodo] = 1;
            } else {
                Queue<Integer> q= new LinkedList<>();
                q.add(nodo);
                int visitado[] = new int[10010];

                for (int j = 1; j <= n; ++j)
                    visitado[j] = -1;
                
                visitado[nodo] = 0;
                Boolean esta = false;
                while(q.size() != 0 && !esta) {
                    int u = q.remove();

                    if(color[u] == 1) {
                        System.out.println(visitado[u]);
                        esta = true;
                        continue;
                    }

                    for (int v: G[u]) {
                        if(visitado[v] == -1) {
                            visitado[v] = visitado[u] + 1;
                            q.add(v);
                        }
                    }
                }

            }
        }
    }
}
