#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define inf 1e9;
vector<int> G[20];
int w[21][21];
int dp[20][1<<20];
int p;
int n,m;
bool f(int u, int mask){
    if(mask == 0){
        for (int i: G[u])
            if(i == p) return true;
        return false;
    }
    if(dp[u][mask] != -1) return dp[u][mask];
    for (int i: G[u]){
        if(mask&(1<<i)){
           if(f(i,mask^(1<<i))) return  (dp[u][mask] = true);
        }
    }
    return (dp[u][mask] =  false);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> m){
        memset(dp,-1,sizeof dp);
        for (int i = 0; i < 21; ++i) G[i].clear();
        for (int i = 0; i < m; ++i){
          int x,y;
          cin >> x >> y;
          G[x].push_back(y);
          G[y].push_back(x);
          w[x][y] = 1;
          w[y][x] = 1;
         }

    int mask = (1<<n)-1;
    if(n == 1) cout << 1 << "\n";
    cout << f(0,mask^(1<<0)) << "\n";
    }
    return 0;
}
