#include <bits/stdc++.h>

using namespace std;

int n,k;
int dp[2010][2010];
const int mod = 1e9 + 7;

int main() {

    cin >> n >> k;

    for (int i = 0; i <= n; ++i)
        dp[k][i] = 1;

    for (int i = k - 1; i >= 0; i--) {
        for (int j = 1; j <= n; ++j) {
            int &ans = dp[i][j];
            for (int l = 1; l * j <= n; ++l) {
                ans += dp[i + 1][j * l];
                ans %= mod;
            }
        }
    }
    
    cout << dp[0][1] << "\n";
    return 0;
}

