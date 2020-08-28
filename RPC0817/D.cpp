#include <bits/stdc++.h>

using namespace std;

int v[4010],n;
int dp[4010];
int f(int pos){
    if(pos == n) return 0;
    int ans = 1e9;
    if(dp[pos] != -1) return dp[pos];
    for (int i = pos + 1; i < n; ++i)
        ans = min(ans,f(i + 1) + max(v[i] - v[pos] - 1800 + 20, 20 * (i - pos + 1)) + 120);
    ans = min(ans,f(pos + 1) + 140);
    return dp[pos] = ans;

}

int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        scanf("%d",v + i);
    memset(dp,-1,sizeof dp);
    printf("%d\n", f(0));
    return 0;
}

