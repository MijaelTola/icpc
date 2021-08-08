#include <bits/stdc++.h>

using namespace std;

vector<int> G[200010];
vector<int> depth[200010];
vector<int> dd[200010];;
int ini[200010];
int fin[200010];
vector<int> e;
int n;

void dfs(int u, int d = 0, int p = -1) {
    depth[d].push_back(u);
    e.push_back(u);
    ini[u] = e.size();
    fin[u] = e.size();
    for (int v: G[u]) {
        if(v == p) continue;
        dfs(v, d + 1, u);
        e.push_back(u);
        fin[u] = e.size();
    }
}

void f(int u, int d = 0, int p = -1) {
    dd[d].push_back(ini[u]);
    for (int v: G[u]) {
        if(v == p) continue;
        f(v, d + 1, u);
    }
}

int main() {
    
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        G[x].push_back(i);
        G[i].push_back(x);
    }

    dfs(1);
    f(1);

    for (int i = 1; i <= n; ++i) {
        sort(dd[i].begin(), dd[i].end());
    }
    
    int q;
    cin >> q;

    while(q--) {
        int u,d;
        cin >> u >> d;
        int l = ini[u], r = fin[u];
        int a = lower_bound(dd[d].begin(), dd[d].end(), l) - dd[d].begin();
        int b = upper_bound(dd[d].begin(), dd[d].end(), r) - dd[d].begin();
        cout << b - a << "\n";
    }
    return 0;
}

