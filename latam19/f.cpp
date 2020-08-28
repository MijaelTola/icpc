#include <bits/stdc++.h>

using namespace std;

long long dp[5010][5010];
const int mod = 1e9 + 7;

long long f(int n, int m) {
    if(m == 0) return 1;
    if(n <= 0) return 0;
    long long &ans = dp[n][m];
    if(ans != -1) return ans;
    ans = 0;
    if(m - n >= 0) ans += f(n, m - n) ;
    ans %= mod;
    if(n - 2 >= 0 and n - 1 >= 0) {
        ans += ((2 * f(n - 1, m)) % mod - f(n - 2, m) + mod) % mod;
        ans %= mod;
    }
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    int x,y;
    cin >> x >> y;
    cout << f(x,y - x) << "\n";
    return 0;
}

