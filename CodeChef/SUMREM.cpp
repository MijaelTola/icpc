#include <bits/stdc++.h>

using namespace std;

int t,n,X,x,y;
int v[100010];
int del[100010];
int depth[100010];
int childs[100010];
int parent[100010];
vector<int> G[100010];
long long sum[100010];

long long dfs(int u, int p) {
    sum[u] = v[u];
    childs[u] = 1;
    for (int v: G[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        sum[u] += dfs(v, u);
        parent[v] = u;
        childs[u] += childs[v];
    }
    return sum[u];
}

void check(int u, int p) {
    del[u] = 1;
    for (int v: G[u])
        if(v != p and !del[v]) check(v, u);
}

int main() {
    scanf("%d", &t);
    while(t--) {
        vector<pair<int,int> > neg;
        for (int i = 0; i < 100010; ++i) {
            G[i].clear();
            del[i] = depth[i] = childs[i] = parent[i] = sum[i] = 0;
        }
        scanf("%d %d", &n, &X);
        for (int i = 0; i < n; ++i)
            scanf("%d", v + i);

        for (int i = 0; i < n - 1; i++) {
            scanf("%d %d", &x, &y);
            x--,y--;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        depth[0] = 1;
        dfs(0, -1);

        long long total = 0;
        for (int i = 0; i < n; ++i) {
            total += v[i];
            if(v[i] < 0) neg.push_back({depth[i], i});
        }
        sort(neg.begin(), neg.end());
        int cnt = 1;
        long long ans = total;
        for (int i = 0; i < (int)neg.size(); ++i) {
            if(del[neg[i].second]) continue;
            long long path = sum[neg[i].second];
            long long cur = total - path;
            if(cur - X * cnt > cur + path) {
                ans -= path;
                cnt++;
                check(neg[i].second, parent[neg[i].second]);
            }
        }
        printf("%lld\n", ans - X * (cnt - 1));
    }
    return 0;
}

