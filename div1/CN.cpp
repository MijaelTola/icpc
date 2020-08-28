#include <bits/stdc++.h>

using namespace std;

int dp[10010][10010];

int mod = 1e9 + 7;

int f(int u, int cur) {
    if (u == 0) return 1;
    if (u < 0 or cur > 10000) return 0;
    if(dp[u][cur] != -1) return dp[u][cur];
    int ans = 0;
    ans = (ans + f(u - cur, cur)) % mod;
    ans = (ans + f(u, cur + 1)) % mod;
    return dp[u][cur] = ans;
}


int main(){

    memset(dp, -1, sizeof dp);
    f(10000,1);
    int t; cin >> t;
    while(t--) {
        int x;
        cin >> x;
        cout << f(x,1) << "\n";
    }
    return 0;
}

