#include <bits/stdc++.h>

using namespace std;

int n;
int v[3010];

long long dp[3010][3010][2];

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> v[i];


    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j + i < n; ++j) {
            int sz = i + j;
            
            dp[i][sz][1] = max(dp[i][sz][1], dp[i + 1][sz][0] + v[i]);
            dp[i][sz][1] = max(dp[i][sz][1], dp[i][sz - 1][0] + v[sz]);

            dp[i][sz][0] = min(dp[i][sz][0], dp[i + 1][sz][1] - v[i]);
            dp[i][sz][0] = min(dp[i][sz][0], dp[i][sz - 1][1] - v[sz]);
        }
    }
    cout << dp[0][n - 1][1] << "\n";
    return 0;
}

