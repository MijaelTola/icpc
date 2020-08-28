#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> G[100010];
int way[100010];
int deg[100010];

bool dfs(int u, int dk, int p = -1) {
    if(dk) {
        if(deg[u] < 3) return 0;
    } else {
        if(deg[u] >= 3) return 0;
        return 1;
    }

    bool ans = 1;
    
    for (int v: G[u]) {
        if(v == p) continue;
        deg[v]--;
        ans &= dfs(v, dk - 1, u);
    }
    return ans;
}
int main() {

    cin >> n >> k;

    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    
    auto bfs = [&] (int u) {
        memset(way, -1, sizeof way);
        queue<pair<int,int> > q;
        way[u] = u;
        q.push({u,1});

        int mx = 0, id = -1;

        while(!q.empty()) {
            int u = q.front().first;
            int d = q.front().second;
            q.pop();
            if(d > mx) {
                mx = d;
                id = u;
            }

            for (int v: G[u]) {
                if(way[v] == -1) {
                    q.push({v, d + 1});
                    way[v] = u;
                }
            }
        }
        return make_pair(id, mx);
    };

    auto p = bfs(1);
    p = bfs(p.first);
    
    int diametro = p.second;
    if(diametro % 2 == 0) return cout << "No\n", 0;

    int mid = p.first;

    for (int i = 0; i < (diametro) / 2; ++i) {
        mid = way[mid];
    }
    
    if( dfs(mid, k) ) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

