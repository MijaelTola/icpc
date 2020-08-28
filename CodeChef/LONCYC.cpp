#include <bits/stdc++.h>

using namespace std;

vector<int> G[200010];
int status[200010];
int vis[200010];
bool dfs(int u, int parent) {
    vis[u] = 1;
    status[u] = 1;
    bool cycle = 0;
    for (int i = 0; i < (int)G[u].size(); ++i) {
        int v = G[u][i];
        if(v == parent or status[v] == 2) continue;
        if(status[v] == 1) continue;
        bool ver = dfs(v,u);
        if(!ver) {
            vis[u] += vis[v];
            cycle = 1;
        }
    }
    status[u] = 2;
    return cycle;
}
int main(){
    
    int t,n,m;
    scanf("%d", &t);
    while(t--) {
        for (int i = 0; i < 200010; ++i) {
            G[i].clear();
            status[i] = 0;
        }
        scanf("%d %d",&n, &m);
        for (int i = 0 ; i < n; ++i) {
            int x,y;
            scanf("%d %d", &x, &y);
        }
    }
    return 0;
}

