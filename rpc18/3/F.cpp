#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int dp[110][10010];
int dh,dw;
int f(int pos, int l) {
    if(pos == dw) return 1;
    if(dp[pos][l] != -1) return dp[pos][l];
    int ans = 0;
    for (int i = 0; i <= dh; ++i) {
        if(l - i >= 0)ans = (ans + f(pos + 1,l - i)) % mod;
    }
    return dp[pos][l] = ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    memset(dp,-1,sizeof dp);
    int n;
    cin >> n >> dw >> dh;
    int cur = 0;
    int ans = 0;
    for (int i = 0; i <= dh; ++i) {
        ans = (ans + f(1,n - i)) % mod;
        cur += (i * dw <= n);
    }
    cout << ((ans - cur) + mod) % mod<< "\n";
    return 0;
}

