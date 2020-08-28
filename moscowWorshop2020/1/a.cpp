#include <bits/stdc++.h>

using namespace std;

int n,m;
int match[600];
int vis[600];
vector<int> G[600];

bool dfs(int u) {
    if(vis[u]) return 0;
    vis[u] = 1;
    for (int v: G[u]) {
        if(match[v] == -1 or dfs(match[v])) {
            match[u] = v;
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int main() {
    memset(match, -1, sizeof  match);
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        int x;
        while(cin >> x and x) {
            G[i].push_back(x + n);
            G[x + n].push_back(i);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if(match[i] == -1) {
            memset(vis, 0, sizeof vis);
            dfs(i);
        }
    }
    
    vector<pair<int,int> > ans;

    for (int i = 1; i <= n; ++i) {
        if(match[i] != -1) {
            ans.emplace_back(i, match[i] - n);
        }
    }
        
    cout << ans.size() << "\n";
    for (auto p: ans)
        cout << p.first << " " << p.second << "\n";
    
    return 0;
}

