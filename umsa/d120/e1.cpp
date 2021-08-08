#include <bits/stdc++.h>

using namespace std;


const int N = 1e5 + 10;
const long long inf = LLONG_MAX;

struct edge{int to, rev; long long f, cap;};

int Nflow, q[N], dist[N], work[N];

vector <edge> adj[N];
vector<int> paths[N];
vector<long long> flow;

void addEdge(int from, int to, long long cap, long long revcap = 0) {
  adj[from].push_back((edge){to, (int) adj[to].size(), 0, cap});
  adj[to].push_back((edge){from, (int) adj[from].size() - 1, 0, revcap});
}
                    
bool dinic_bfs(int source, int sink) {
  fill(dist, dist + Nflow, -1);dist[source] = 0; q[0] = source;
  int qt = 1;
  for (int qh = 0; qh < qt; qh++) {
    int u = q[qh];
    for (int i = 0; i < (int)adj[u].size(); i++) {
      auto e = adj[u][i];
      int v = e.to;
      if (dist[v] == -1 && e.cap - e.f > 0) {
        q[qt++] = v;
        dist[v] = dist[u] + 1;
      }
    }
  }
  return dist[sink] != -1;
} 
                    
long long dinic_dfs(int u, int sink, long long minEdge) {
  if (u == sink) return minEdge;
  for (int &i = work[u]; i < (int)adj[u].size(); i++) {
    auto e = adj[u][i];
    int v = e.to;
    if (dist[v] == dist[u] + 1 && e.cap - e.f > 0) {
      long long flow = dinic_dfs(v, sink, min(minEdge, e.cap - e.f));
      if (flow) {
        adj[u][i].f += flow;
        adj[v][e.rev].f -= flow;
        return flow;
      }
    }
  }
  return 0;
}
                    
long long maxflow(int source, int sink) {
  long long mf = 0;
  //cerr << "asdasd";
  while (dinic_bfs(source, sink)) {
    fill(work, work + Nflow, 0);
    //cerr << "asdasd";
    while (long long flow = dinic_dfs(source, sink, inf)) mf += flow;
  }
  return mf;
}

long long dfs(int u, int p, long long minFlow, int sink, int id) {
    if(u == sink) {
    return minFlow;
  }
  for (int i = 0; i < (int)adj[u].size(); i++) {
    auto e = adj[u][i];
    int v = e.to;
    if(v != p and e.f > 0) {
      int pc = dfs(v, u, min(minFlow, e.f), sink, id);
      if(pc) {
        adj[u][i].f -= pc;
        paths[id].push_back(v);
        return pc;
      }
    }
  }
  return 0;
}



int main() {

    int m,a,b,t;
    cin >> m >> a >> b >> t;

    vector<int> da,db;

    for (int i = 0; i < a; ++i) {
        int x;
        cin >> x;
        da.push_back(x);
    }

    for (int i = 0; i < b; ++i) {
        int x;
        cin >> x;
        db.push_back(x);
    }
    
    int ini = 1005;
    int fin = 1006;

    int mid = 1007;

    for (int i = 0; i < a; ++i) {
        for (int j = i + 1; j < b; ++j) {
            if(abs(da[i] - db[j]) < t) {
                addEdge(i + 1, a + j + 1, 1);
            }
        }
    }

    addEdge(ini, mid, m);
    
    for (int i = 0; i < a; ++i) {
        addEdge(mid, i + 1, 100000);
    }
    
    for (int i = 0; i < b; ++i) {
        addEdge(a + i + 1, fin, 100000);
    }

     Nflow = fin + 2;
    long long temp =  maxflow(ini, fin); 
    cout << temp << endl;
    //if(flow() == m) cout << "S\n";
    //else cout << "N\n";
    return 0;
}
