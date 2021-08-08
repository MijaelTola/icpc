#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
long long min_cut;
long long G[1010][1010];
vector<int> adj[1010];
bool vis[1010];
int way[1010];
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

    int mx = 0;
    for (int i = 0; i < a; ++i) {
        for (int j = i + 1; j < b; ++j) {
            if(abs(da[i] - db[j]) < t) {
                G[i + 1][a + j + 1] += 1;
                G[a + j + 1][i + 1] += 1;
                adj[i + 1].push_back(a + j + 1);
                adj[a + j + 1].push_back(i + 1);
                mx = max(mx, a + j + 1);
            }
        }
    }

    int ini = 1001;
    int ini2 = 1001;
    int fin = 1003;
    

    G[ini][ini2] += m;
    G[ini2][ini] += m;
    
    for (int i = 0; i < a; ++i) {
        G[ini2][i + 1] += 100000;
        G[i + 1][ini2] += 100000;
        adj[i + 1].push_back(ini2);
        adj[ini2].push_back(i + 1);
    }

    for (int j = 0; j < b; ++j) {
        G[a + j + 1][fin] = 10000;
        G[fin][a + j + 1] = 10000;
        adj[a + j + 1].push_back(fin);
        adj[fin].push_back(a + j + 1);
    }

    
    cout << max_flow(ini,fin) << "\n";
    if(max_flow(ini,fin) == m) cout << "S\n";
    else cout << "N\n";

    
           


    return 0;
}

