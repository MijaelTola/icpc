#include <bits/stdc++.h>

using namespace std;

int n,m;
bool vis[8010];
vector<int> G[8010];
int pl[8010];

void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for (int v: G[u]) {
        dfs(v);
    }
}

int main() {
    memset(pl, -1, sizeof pl);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            G[i].push_back(x + n);
            G[x + n].push_back(i);
        }
    }

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if(!x) continue;
        pl[i] = x + n;
        pl[x + n] = i;
    }

    for (int i = 1; i <= n; ++i) {
        if(pl[i] == -1 and !vis[i]) {
            dfs(i);
        }
    }
    vector<int> l,r;

    for (int i = 1; i <= n; ++i) {
        if(!vis[i]) l.push_back(i);
    }
    for (int i = 1; i <= m; ++i) {
        if(vis[i + n]) r.push_back(i);
    }

    cout << l.size() + r.size() << "\n";
    cout << l.size() << " ";
    for (int x: l) cout << x << " ";
    cout << "\n";
    cout << r.size() << " ";
    for (int x: r) cout << x << " ";
    cout << "\n";

}

