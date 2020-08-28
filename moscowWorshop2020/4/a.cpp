#include <bits/stdc++.h>

using namespace std;

const int N = 120;
const long long inf = LLONG_MAX;

struct edge{int to, rev; long long f, cap;};

int Nflow, q[N], dist[N], work[N];

vector <edge> adj[N];

void addEdge(int from, int to, long long cap, long long revcap = 0) {
  adj[from].push_back((edge){to, (int)adj[to].size(), 0, cap});
  adj[to].push_back((edge){from, (int)adj[from].size() - 1, 0, cap});
}
                    
bool dinic_bfs(int source, int sink) {
  fill(dist, dist + Nflow, -1);dist[source] = 0; q[0] = source;;
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
  while (dinic_bfs(source, sink)) {
    fill(work, work + Nflow, 0);
    //cerr << "asdasd";
    while (long long flow = dinic_dfs(source, sink, inf)) mf += flow;
  }
  return mf;
}

int main() {
  int n,m ;scanf("%d %d", &n, &m);
  map < pair <int, int>, queue <int> > idx;
  vector <pair <int, int> > z;
  for (int i = 0; i < m; i++) {
    int u, v, w; scanf("%d %d %d", &u, &v, &w);
    u--, v--;
    addEdge(u, v, w, w);
    //addEdge(v, u, w);
    z.push_back({u, v});
    idx[{u, v}].push(adj[u].size() - 1);
    //idx2[{u, v}] = adj[v].size() - 1;
  }
  Nflow = n;
  long long temp =  maxflow(0, n - 1);
  printf("%lld\n", temp);
  for (int i = 0; i < m; i++) {
    int u = z[i].first;
    int v = z[i].second;
    //cerr << adj[u][idx[{u, v}]].f << endl;
    //cerr << adj[v][idx2[{v, u}]].f << endl;
    printf("%lld\n", adj[u][idx[{u, v}].front()].f);idx[{u, v}].pop();
  }
  return 0;
}
