#include <bits/stdc++.h>

using namespace std;

int t,n;
long long v[100010];
long long m[100010];
long long gcd[100010];
int depth[100010];
vector<int> G[100010];

void dfs(int u, int p) {
    depth[u] = 1;
    for (int vv: G[u]) {
        if(vv == p) continue;
        gcd[vv] = __gcd(v[vv], gcd[u]);
        dfs(vv, u);
        depth[u] += depth[vv];
    }
}

int main() {
    scanf("%d", &t);
    while(t--) {
        for (int i = 0; i < 100010; ++i) {
            G[i].clear();
            gcd[i] = depth[i] = 0;
        }
        scanf("%d", &n);
        for (int i = 0; i < n - 1; i++) {
            int x,y;
            scanf("%d %d", &x, &y);
            x--,y--;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        for (int i = 0; i < n; ++i) 
            scanf("%lld", v + i);

        for (int i = 0; i < n; ++i) 
            scanf("%lld", m + i);
        gcd[0] = v[0];
        dfs(0, -1);
        for (int i = 0; i < n; ++i) {
            if(depth[i] != 1) continue;
            int curg = __gcd(gcd[i], m[i]);
            if(curg != 1) printf("%lld ", m[i] - curg);
            else printf("%lld ", m[i] - 1);
        }
        puts("");
    }
    return 0;
}

