#include <bits/stdc++.h>

using namespace std;

int n;
double v[3010];
double dp[3010][3010];

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    
    for (int i = n / 2 + 1; i <= n; ++i)
        dp[n][i] = 1.0;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] += dp[i + 1][j + 1] * v[i];
            dp[i][j] += dp[i + 1][j] * (1 - v[i]);
        }
    }
    
    printf("%.15lf\n", dp[0][0]);
    return 0;
}

