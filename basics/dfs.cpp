#include <bits/stdc++.h>

using namespace std;

vector<int> G[100];
bool vis[110];

void dfs(int u) {
    cout << u << "\n";
    vis[u] = 1;
    for (int i = 0; i < (int)G[u].size(); ++i) {
        int v = G[u][i];
        if(!vis[v]) {
            dfs(v);
        }
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 1;
        cout << u << "\n";
        for (int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i];
            if(!vis[v]) q.push(v);
        }
    }
}

int main() {
    
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    dfs(1);
    bfs(1);

    /*
    for (int i = 1; i <= n; ++i) {
        cout << i << ": ";
        for (int j = 0; j < (int)G[i].size(); ++j) {
            cout << G[i][j] << " ";
        }
        cout << "\n";
    }*/
    return 0;
}

