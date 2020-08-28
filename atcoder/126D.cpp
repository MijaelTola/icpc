#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int> > G[100010];
long long dis[100010];
int ans[100010];

void f(int u, int p) {
    if(dis[u] % 2 == 0) ans[u] = 1;
    for (auto v: G[u]) {
        if(v.first == p) continue;
        dis[v.first] = dis[u] + v.second;
        f(v.first, u);
    }
}

int main() {
    
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int x,y,w;
        cin >> x >> y >> w;
        G[x].push_back({y,w});
        G[y].push_back({x,w});
    }
 
    f(1,1);

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << "\n";

    return 0;
}

