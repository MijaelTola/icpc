#include <bits/stdc++.h>

using namespace std;

vector<int> G[1010],G2[1010],topo;
int vis[1010];

bool cycle(int u) {
    if(vis[u] == 2) return 0;
    if(vis[u] == 1) return 1;
    vis[u] = 1;
    bool ans = 0;
    for (int i = 0; i < (int)G[u].size(); ++i) 
        ans |= cycle(G[u][i]);  
    vis[u] = 2;
    return ans;
}

void components(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for (int i = 0; i < (int)G[u].size(); ++i) 
        components(G[u][i]);
}

void topoSort(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for (int i = 0; i < (int)G[u].size(); ++i)
        topoSort(G[u][i]);
    topo.push_back(u);
}

void dfs(int u) {
    for (int i = 0; i < (int) G[u].size(); ++i) {
        if(vis[u] + 1 > vis[G[u][i]]) {
            vis[G[u][i]] = vis[u] + 1;
            dfs(G[u][i]);
        }
    }
}

int main () {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int c; cin >> c;
        for (int j = 0; j < c; ++j) {
            int x; cin >> x; x--;
            G[i].push_back(x);
        }
    }

    memset(vis, 0,sizeof vis);
    for (int i = 0; i < n; ++i)
        if(cycle(i)) return cout << "NO\n",0;

    memset(vis, 0,sizeof vis);
    for (int i = 0; i < n; ++i) 
        if(!vis[i]) topoSort(i);
    
    for (int i = topo.size() - 1; i >= 0; --i) 
        dfs(i);
    
    set<pair<int,int> > s;
    for (int i = topo.size() - 1; i >= 0; --i) {
        for (int j = 0; j < (int)G[topo[i]].size(); ++j) {
            int u = topo[i];
            int v = G[topo[i]][j];
            if(vis[u] + 1 == vis[v]) {
                if(s.count(make_pair(u,v))) continue;
                s.insert(make_pair(u,v));
                G2[u].push_back(v);
                G2[v].push_back(u);
            }
        }
    }
    memset(vis, 0, sizeof vis);
    int c = 0;
    for (int i = topo.size() - 1; i >= 0; --i) {
        if(!vis[topo[i]]) {
            c++;
            components(topo[i]);
        }
    }
    if(c > 1 or (int)s.size() != n - 1) return cout << "NO\n",0;

    cout << "YES\n";
    for (pair<int,int> p: s)
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    return 0;
}
