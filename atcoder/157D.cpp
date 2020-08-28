#include <bits/stdc++.h>

using namespace std;

int n,m,k,a,b,c;
vector<int> G[100010];
vector<pair<int,int> > e;
int comp[100010];
int cnt[100010];
int bel[100010];
long long ans[100010];

void dfs(int u) {
    if(comp[u] != -1) return;
    comp[u] = c;
    cnt[c]++;
    for (int v: G[u])
        dfs(v);
}

int main() {
    memset(comp, -1, sizeof comp);

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
        e.emplace_back(a,b);
    }

    for (int i = 0; i < k ; ++i) {
        scanf("%d %d", &a, &b);
        e.emplace_back(a,b);
    }
    c = 0;

    for (int i = 1; i <= n; ++i) {
        if(comp[i] == -1) {
            c++;
            dfs(i);
        }
    }
    
    for (auto p: e) {
        if(comp[p.first] == comp[p.second]) 
            bel[p.first]++, bel[p.second]++;
    }

    for (int i = 1; i <= n; ++i) {
        int cur = cnt[comp[i]] - 1 - bel[i];
        //cout << i << ": " << cnt[comp[i]] - 1 << " " << bel[i] << " test\n";
        printf("%d ", cur);
    }
    puts("");
    return 0;
}

