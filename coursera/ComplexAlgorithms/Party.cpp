#include <bits/stdc++.h>

using namespace std;

vector<int> G[100010];
int w[100010];
int dp[100010];
int n;

//MAX WEIGHT INDEPENDENT SET
int f(int v, int parent){
    if(dp[v] != -1) return dp[v];
    int sz = 0;
    for (int u: G[v]) sz += (u != parent);
    if(!sz) return dp[v] = w[v];

    int m1 = w[v];

    for (int u: G[v]){
        if(u == parent) continue;
        for (int ww: G[u]){
            if(ww == u or ww == v) continue;
            m1 += f(ww,u);
        }
    }

    int m0 = 0;

    for (int u: G[v]){
        if(u == parent) continue;
        m0 += f(u,v);
    }
    return dp[v] = max(m0,m1);
}

int main(){
    memset(dp,-1,sizeof dp);
    scanf("%d",&n);

    for (int i = 1; i <= n; ++i)
        scanf("%d",w + i);
    
    for (int i = 0; i < n - 1; ++i){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        if(dp[i] == -1)
            ans = max(ans,f(i,-1));
    }
    printf("%d\n",ans);
    return 0;
}

