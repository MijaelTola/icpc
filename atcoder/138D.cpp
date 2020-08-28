#include <bits/stdc++.h>

using namespace std;

int n,q;
vector<int> G[200010];
int val[200010];
int ans[200010];

void dfs(int u, int p, int cur) {
    ans[u] = cur + val[u];   
    for (int v: G[u]) {
        if(v == p) continue;
        dfs(v,u, ans[u]);
    }
}

int main() {
    
    scanf("%d %d", &n, &q);

    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    while(q--) {
        int p,x;
        scanf("%d %d", &p, &x);
        val[p] += x;
    }

    dfs(1,1,0);

    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);

    puts("");
    return 0;
}

