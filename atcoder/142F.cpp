#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> G[1010], GT[1010];
int scc[1010];
bool vis[1010];

stack<int> s;

void dfs(int u) {
    for (int v: G[u]) {
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v);
    }
    s.push(u);
}

void dfs(int u, int comp) {
    for (int v: GT[u]) {
        if(scc[v] != -1) continue;
        scc[v] = comp;
        dfs(v, comp);
    }
}
int main() {
    memset(scc, -1, sizeof scc);
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        GT[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i)
        if(!vis[i]) {
            vis[i] = 1;
            dfs(i);
        }

    int comp = 0;

    while(!s.empty()) {
        int u = s.top();
        s.pop();
        if(scc[u] == -1) {
            scc[u] = ++comp;
            dfs(u, comp);
        }
    }

    vector<int> ans;

    for (int i = 1; i <= n; ++i)
        if(scc[i] == 1) ans.push_back(i);

    if(ans.size() <= 1) return cout << "-1\n",0;
    cout << ans.size() << "\n";

    for (int x: ans)
        cout << x << "\n";
    return 0;
}

