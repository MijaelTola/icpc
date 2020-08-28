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
    for (int i = 0; i < adj[u].size(); i++) {
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
  for (int &i = work[u]; i < adj[u].size(); i++) {
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
  while (dinic_bfs(source sink)) {
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
  for (int i = 0; i < adj[u].size(); i++) {
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
  int n, m, s, t ;scanf("%d %d %d %d", &n, &m, &s, &t);
  map < pair <int, int>, queue <int> > idx;
  vector <pair <int, int> > z;
  for (int i = 0; i < m; i++) {
    int u, v, w = 1; scanf("%d %d", &u, &v);
    u--, v--;
    if(u == v) continue;
    addEdge(u, v, w, w);
    //addEdge(v, u, w);
    z.push_back({u, v});
    idx[{u, v}].push(adj[u].size() - 1);
    //idx2[{u, v}] = adj[v].size() - 1;
  }
  Nflow = n;
  long long temp =  maxflow(s - 1, t - 1);  
  if(temp < 2) {
    cout << "NO\n";
    return 0;
  }
  int k = 0;
  flow.clear();
  while(true) {
    paths[k].clear();
    long long p = dfs(s - 1, s - 1, inf, t - 1, k);
    flow.push_back(p);
    if(p == 0) break;
    k++;
  }
  cout << "YES\n";
  for(int i = 0; i < 2; i++) {
    cout << s;
    for(int j = paths[i].size() - 1; j >= 0; j--) {
      cout << " " << paths[i][j] + 1;
    } cout << "\n";
  }
  return 0;
} 
