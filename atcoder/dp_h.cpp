#include <bits/stdc++.h>

using namespace std;

char c[1010][1010];
int dp[1010][1010];
int mod = 1e9 + 7;
int n,m;
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> c[i][j];

    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(c[i][j] == '#') continue;
            if(i) dp[i][j] += dp[i - 1][j];
            dp[i][j] %= mod;
            if(j) dp[i][j] += dp[i][j - 1];
            dp[i][j] %= mod;
        }
    }

    cout << dp[n - 1][m - 1] << "\n";
    return 0;
}

