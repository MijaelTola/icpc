#include <bits/stdc++.h>

using namespace std;

int n,m,k;
vector<int> G[1010];
int c[1010];
int comp[1010];
bool vis[1010];
bool has[1010];
int sz[1010];
int e[1010];
int cnt[1010];
int cur = 0;
vector<pair<int,int> > edges;

void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    comp[u] = cur;
    sz[cur]++;
    for (int v: G[u]) {
        dfs(v);
    }
}

int main() {
    
    cin >> n >> m >> k;

    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        c[x] = 1;
    }

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
        edges.push_back({x,y});
    }

    for (int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            dfs(i);
            cur++;
        }
    }

    for (int i = 1; i <= n; ++i) 
        if(c[i])has[comp[i]] = 1;
    
    for (auto p: edges) 
        cnt[comp[p.first]]++;
    
    int id = -1;
    int mx = 0;

    for (int i = 0; i < cur; ++i) {
        if(has[i] and sz[i] > mx) {
            mx = sz[i];
            id = i;
        }
    }

    for (int i = 0; i < cur; ++i) {
        if(!has[i]) {
            cnt[id] += cnt[i];
            sz[id] += sz[i];
        }
    }
    
    int ans = 0;

    for (int i = 0; i < cur; ++i) {
        if(has[i]) {
            int total = (sz[i] * (sz[i] - 1)) / 2;
            total -= cnt[i];
            ans += total;
        }
    }

    cout << ans << "\n";


 
    return 0;
}

