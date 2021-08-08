#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int n;

int dp[1000010][2][2];

int main() {

    cin >> n;

    dp[n][1][1] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                int &ans = dp[i][j][k];
                for (int l = 1; l < 9; ++l) {
                    ans += dp[i + 1][j][k];
                    ans %= mod;
                }
                ans += dp[i + 1][1][k];
                ans %= mod;
                ans += dp[i + 1][j][1];
                ans %= mod;
            }
        }
    }

    cout << dp[0][0][0] << "\n";
    
    return 0;
}

