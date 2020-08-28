#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int dp[10010l][10010],n;

int f(int x,int cur) {
    if(x == 0) return 1;
    if(cur < 1) return 0;
    if(dp[x][cur] != -1) return dp[x][cur];
    int ans = 0;
    if(x - cur >= 0) ans = (ans + f(x - cur, cur)) % mod;
    ans = (ans + f(x,cur - 1)) % mod;
    return dp[x][cur] = ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    while(scanf("%d", &n) != EOF) printf("%d\n", f(n,n));
    return 0;
}

