#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[510][6][6];

int main() {
    
    cin >> n;

    dp[n][0][0] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= 5; ++j) {
            for (int k = 0; k <= 3; ++k) {
                for (int l = 0; l <= j; ++l) 
                    for (int m = 0; m <= k; ++m) 
                        dp[i][j][k] += dp[i + 1][j - l][k - m];
            }
        }
    }

    cout << dp[0][5][3] << "\n";

    
    return 0;
}

