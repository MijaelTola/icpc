#include <bits/stdc++.h>

using namespace std;

const int N = 330;
const long long inf = LLONG_MAX;

struct edge{
  int to, rev;
  long long f, cap;
};

vector <edge> adj[N];

int Nflow, q[N], work[N], dist[N];

void addEdge(int from, int to, int cap, int revcap = 0) {
  adj[from].push_back((edge){to, (int)adj[to].size(), 0, cap});
  adj[to].push_back((edge){from, (int)adj[from].size() - 1, 0, revcap});
}

bool dinic_bfs(int source, int sink) {
  fill(dist, dist + Nflow, -1);dist[source] = 0;q[0] = source;
  int qt = 1;
  for (int qh = 0; qh < qt; qh++) {
    int u = q[qh];
    for (int i = 0; i < (int)adj[u].size(); i++) {
      auto e = adj[u][i];
      int v= e.to;
      if (dist[v] < 0 && e.cap - e.f > 0) {
        dist[v] = dist[u] + 1;
        q[qt++] = v;
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
  while (dinic_bfs(source, sink)) {
    fill(work, work + Nflow, 0);
    while (long long flow = dinic_dfs(source, sink, inf)) mf += flow;
  }
  return mf;
}


vector <int> g[N], gr[N];
bool vis[N];



void dfs(int u) {
  vis[u] = 1;
  for (int v : gr[u]) if (!vis[v]) dfs(v);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
      g[i].clear();
      while (1) {
        int x; scanf("%d", &x);
        if (x == 0) break;
        g[i].push_back(x);
        g[x].push_back(i);
      }
    }
    //cerr << "aa" << n << ' '  << m << endl;
    for (int i = 0; i < N; i++) gr[i].clear(), adj[i].clear();
    for (int i = 1; i <= n; i++) {
      set <int> gg;
      for (int v : g[i]) {
        gg.insert(v);
      }
      for (int v = 1; v <= m; v++) {
        if (!gg.count(v)) {

          addEdge(i, v + n, 1);
        }
      }
      addEdge(0, i, 1);
    }
    for (int i = 1; i <= m; i++) addEdge(i + n, n + m + 1, 1);
    Nflow = n + m + 2;
    long long temp = maxflow(0, n + m + 1);
    vector <int> match(n + 1, - 1);
    for (int i = 1; i <= n; i++) {
      for (auto e : adj[i]) {
        int v = e.to;
        if (e.f == 1 && v > n) {
          gr[v].push_back(i);
          match[i] = v;
        }
        else if (v > n) {
          gr[i].push_back(v);
        }
      }
    }
    memset(vis, 0, sizeof vis);
    
    for (int i = 1; i <= n; i++) {
      if (match[i] == -1) dfs(i);
    }
    set <int> vertex_cover, independent_set[2];
    for (int i = 1; i<= n; i++) if (!vis[i]) vertex_cover.insert(i);
    for (int i = 1; i <= m; i++) if (vis[i + n]) vertex_cover.insert(i + n);
    for (int i = 1; i <= n + m; i++) if (!vertex_cover.count(i)) independent_set[i > n].insert(i);

    printf("%d\n%d %d\n", (int)independent_set[0].size() + (int)independent_set[1].size(), (int)independent_set[0].size(), (int)independent_set[1].size());
    for (auto x : independent_set[0]) printf("%d ", x);puts("");
    for (auto x : independent_set[1]) printf("%d ", x - n);puts("");
  }
  return 0;
}
