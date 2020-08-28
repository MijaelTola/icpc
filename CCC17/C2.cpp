#include <bits/stdc++.h>

using namespace std;

int n,k;
const long long mod = 1000000007;
long long dp[100010];
int dp1[100010][10][2];

long long f(int pos){
    if(pos == n) return 1LL;
    if(dp[pos] != -1) return dp[pos];
    long long ans = 0;
    for (int i = pos; i < pos + k; ++i)
        ans = (ans + f(i + 1)) % mod;
    return dp[pos] = ans % mod;
}

int r(int pos, int cur, int flag){
    if(pos == n) return 1;
    if(cur == k) return 0;

    if(dp1[pos][cur][flag] != -1) return dp1[pos][cur][flag];
    int ans = 0;
    if(cur < k) ans += r(pos + 1, cur + 1, flag);
    ans += r(pos + 1, 0, !flag);

    return dp1[pos][cur][flag] = ans;
}
int main(){
    memset(dp1,-1,sizeof dp);
    memset(dp,-1,sizeof dp);
    scanf("%d %d", &n, &k);
    printf("%lld\n", (long long)(f(0) * 2LL) % mod);
    printf("%d\n", r(0,0,0));
    return 0;
}

