#include <bits/stdc++.h>

using namespace std;

vector<int> G[2010];
bool vis[2010][2010];


int main() {
    
    int n,m;

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
    }

    auto bfs = [&](int ini) {
        queue<int> q;
        q.push(ini);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(vis[ini][u]) continue;
            vis[ini][u] = 1;
            for (auto v: G[u]) {
                q.push(v);
            }
        }
    };
    
    for (int i = 1; i <= n; ++i)
        bfs(i);

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ans += vis[i][j];

    cout << ans << "\n";
    
    return 0;
}

