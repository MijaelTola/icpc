#include <bits/stdc++.h>

using namespace std;

int n,x;
vector<int> G[300010];
int sz[300010];
int depth[300010];
const int mod = 1e9 + 7;
long long ans;

int dfs(int u, int p = -1) {
    sz[u] = 1;
    for (int v: G[u]) {
        if(v == p) continue;
        sz[u] += dfs(v, u);
    }
    return sz[u];
}

int dfs2(int u, int p = -1) {
    int mx = 0;
    for (int v: G[u]) {
        if(v == p) continue;
        mx = max(mx, dfs2(v, u));
    }
    return depth[u] = mx + 1;
}

void f(int u, int cur, int p = -1) {
    priority_queue<tuple<int,int,int> > q;
    for (int v: G[u]) {
        if(v == p) continue;
        q.push({depth[v], sz[v], v});
      
    }

    int ini = cur;
    while(!q.empty()) {
        auto [a,c ,b] = q.top();
        q.pop();
        ans = (ans + ini) % mod;
        f(b, ini, u);
        ini += cur;
        ini %= mod;
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {

        cin >> n >> x;
        for (int i = 0; i < n + 10; ++i) {
            G[i].clear();
            sz[i] = 0;
            depth[i] = 0;
        }
    
        for (int i = 0; i < n - 1; ++i) {
            int x,y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        
        dfs(1);
        dfs2(1);
        ans = x;
        f(1,1);

        cout << ans << "\n";
    }
    return 0;
}

