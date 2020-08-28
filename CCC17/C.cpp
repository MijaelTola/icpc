#include <bits/stdc++.h>

using namespace std;

vector<int> G2[1000010];
vector<int> G[500010];
int p[500010];
int ini[500010];
int finish[500010];
int val[500010];
int cnt;
int dfs(int u, int parent){
    val[cnt] = p[u];
    ini[u] = cnt++;
    for (int i = 0; i < (int)G[u].size(); ++i){
        int v = G[u][i];
        if(v == parent) continue;
        dfs(v,u);
    }
    finish[u] = cnt ;
}
int main(){
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n - 1; ++i){
        int x,y;
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i)
        scanf("%d", p + i);
    cnt = 0;
    dfs(1,1);

    for (int i = 0; i < n; ++i)
        G2[val[i]].push_back(i);

    int q;
    scanf("%d", &q);
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        int init = ini[x];
        int fin = finish[x];
        if(G2[y].size() == 0){
            puts("0");
            continue;
        }
        int pos1 = lower_bound(G2[y].begin(),G2[y].end(), init) - G2[y].begin();
        int pos2 = lower_bound(G2[y].begin(),G2[y].end(), fin) - G2[y].begin();
        printf("%d\n",pos2 - pos1);
    }

    return 0;
}

