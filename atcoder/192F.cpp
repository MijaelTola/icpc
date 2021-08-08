#include <bits/stdc++.h>

using namespace std;

int v[110];
long long dp[110][110];

int main() {
    
    int n;
    long long x;
    cin >> n >> x;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    auto f = [&] (int k) -> long long {
        if(x % k != 0) return -1e18;
        memset(dp, 0, sizeof dp);
        for (int i = n; i >= 0; i--) {
            for (int j = k - 1; j >= 0; j--) {
                long long &ans = dp[i][j] = -1e18;
                if(i == n) {
                    if(j % k == 0) ans = 0;
                    else ans = -1e18;
                    continue;
                }
                ans = max(ans, dp[i + 1][j]);
                ans = max(ans, dp[i + 1][(j + v[i]) % k] + v[i]);
            }
        }
        return dp[0][0];
    };


    long long ans = 1e18;

    for (int i = 0; i < n; ++i) {
        auto cur = f(i + 1);
        cout << (i + 1) << ": " << cur << "\n";
        if(cur != -1e18) {
            long long df = x - cur;
            ans = min(ans, df / (i + 1));
        }
    }

    cout << ans << "\n";
    return 0;
}

