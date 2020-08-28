#include <iostream>
#include <cstring>
using namespace std;

int dp[320][100010];
int v[10010];
int n;
int f(int pos, int rest){
    if(rest == 0 or pos == n) return 0;
    if(dp[pos][rest] != -1) return dp[pos][rest];
    int ans = -1;
    if(rest - v[pos] >= 0) ans = max(ans,f(pos+1,rest-v[pos])+v[pos]);
    return dp[pos][rest] =  max(ans,f(pos+1,rest));
}

int main(){
    int W;
    cin >> W >> n;
    memset(dp,-1,sizeof dp);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    cout << f(0,W) << endl;
  /*  for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= W; ++j){
            if(j+v[i] <= W){
                if(dp[i-1][j]+v[i] > dp[i-1][j+v[i]]) dp[i][j+v[i]] = dp[i-1][j]+v[i];
                else dp[i][j+v[i]] = dp[i-1][j+v[i]];
            }
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
        }
    }
    cout << dp[n][W] << endl;*/
    return 0;
}
