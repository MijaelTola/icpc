#include <bits/stdc++.h>

using namespace std;

int n,q,x,y,w;
vector<int> G[5010];
vector<pair<int,int> > e;
int parent[5050];
int depth[5050];
int ans[5050][5050];

void dfs(int u, int p, int d = 0) {
    parent[u] = p;
    depth[u] = d;
    for (int v: G[u]) {
        if(v == p) continue;
        dfs(v, u, d + 1);
    }
}

void build(int a, int b, int color) {
    while(a != b) {
        if(depth[a] < depth[b]) swap(a,b);
        ans[a][parent[a]] = color;
        ans[parent[a]][a] = color;
        a = parent[a];
    }
}

bool check (int a, int b, int color) {
    int mn = 1e9;
    while(a != b) {
        if(depth[a] < depth[b]) swap(a,b);
        mn = min({mn, ans[a][parent[a]], ans[parent[a]][a]});
        a = parent[a];
    }
    return mn == color;   
}

int main() {

    for (int i = 0; i < 5050; ++i)
        for (int j = 0; j < 5050; ++j)
            ans[i][j] = 1e6;
    scanf("%d", &n);

    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
        e.emplace_back(x,y);
    }

    dfs(1,1);
    vector<pair<pair<int, int>, pair<int,int> > > v;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d", &x, &y, &w);
        v.push_back({{w,i}, {x,y}});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < q; ++i) {
        auto p = v[i];
        build(p.second.first, p.second.second, p.first.first);
    }

    bool flag = 1;

    for (int i = 0; i < q; ++i) {
        auto p = v[i];
        flag &= check(p.second.first, p.second.second, p.first.first);
    }

    if(!flag) return puts("-1");
 
    for (int i = 0; i < n - 1; ++i) {
        auto p = e[i];
        printf("%d ", ans[p.first][p.second]);
    }
    puts("");
    return 0;
}

