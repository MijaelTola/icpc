#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
long long min_cut;
long long G[110][110];
vector<int> adj[110];
bool vis[110];
int way[110];
int n,m;

bool bfs(int s, int t) {
    memset(vis, 0, sizeof vis);
    memset(way, -1, sizeof way);
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(vis[u]) continue;
        if(u == t) return 1;
        vis[u] = 1;
        for (int v: adj[u]) {
            if(G[u][v] > 0 and !vis[v]) {
                way[v] = u;
                q.push(v);
            }
        }
    }
    return vis[t];
}

long long max_flow(int s, int t) {
    long long ans = 0;
    while(bfs(s,t)) {
        int u = way[t];
        int v = t;
        long long mn = 1e9;
        
        while(u != -1) {
            mn = min(mn,G[u][v]);
            v = u;
            u = way[u];
        }
        
        u = way[t];
        v = t;
        while(u != -1) {
            G[u][v] -= mn;
            G[v][u] += mn;
            v = u;
            u = way[u];
        }
        ans += mn;
    }
    return ans;
}


void dfs(int u) {
    vis[u] = 1;
    for (int v = 1; v <= n; ++ v) {
        if(G[u][v] and !vis[v]) 
            dfs(v);
    }
}

int main() {

    cin >> n >> m;
    vector<tuple<int,int,int> > e;  
    for (int i = 0; i < m; ++i) {
        int x,y,w;
        cin >> x >> y >> w;
        G[x][y] += w;
        G[y][x] += w;
        adj[x].push_back(y);
        adj[y].push_back(x);
        e.push_back({x,y,w});
    }

    max_flow(1, n);
    memset(vis, 0, sizeof vis);

    dfs(1);
    min_cut = 0;
    for (int i = 0; i < (int)e.size(); ++i) {
        int x,y,w;
        tie(x,y,w) = e[i];
        if(vis[x] and !vis[y])  {
            ans.emplace_back(i + 1);
            min_cut += w;
        }
    }

    cout << ans.size() << " " << min_cut << "\n";
    for (auto p: ans)
        cout<< p << " ";
    cout << "\n";
    return 0;
}

