#include <bits/stdc++.h>

using namespace std;

int v[100010][3];
int dp[100010][3],n;
int f(int pos, int last){
    if(pos == n) return 0;
    if(dp[pos][last] != -1) return dp[pos][last];
    int ans = 1e9;
    for (int i = 0; i < 3; ++i){
        if(i == last) continue;
        ans = min(ans,f(pos + 1, i) + v[pos][i]);
    }
    return dp[pos][last] = ans;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(dp,-1,sizeof dp);
        cin >> n;
        for (int i = 0; i < n; ++i)
            scanf("%d %d %d",&v[i][0],&v[i][1],&v[i][2]);
        printf("%d\n",f(0,4));
    }
    return 0;
}

