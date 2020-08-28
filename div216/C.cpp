#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

vector<pair<int,int> > G[100010];
ll d[100010];

void dfs(int u){
    for (int i = 0; i < (int)G[u].size(); ++i){
        pair<int,int> v = G[u][i];
        if(d[v.first] == -1){
            d[v.first] = d[u] + v.second;
            dfs(v.first);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    ll total = 0;
    for (int i = 0; i < n; ++i){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        G[x].push_back(make_pair(y,w));
        G[y].push_back(make_pair(x,w));
        total += w;
    }
    memset(d,-1,sizeof d);
    d[0]=0;
    dfs(0);
    int q; 
    scanf("%d",&q);
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        ll dist = abs(d[x]-d[y]);
        ll rest = total - dist;
        dist = min(rest,dist);
        printf("%lld\n",dist);
    }
    return 0;
}
