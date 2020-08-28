#include <bits/stdc++.h>

using namespace std;

int v[2][200010];
long long dp[200010][2];
int main() {

    int n;
    cin >> n;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> v[i][j];
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 2; ++j) {
            if(j == 1) 
                dp[i][j] = max(dp[i][j], dp[i + 1][0] + v[0][i]);
            else 
                dp[i][j] = max(dp[i][j], dp[i + 1][1] + v[1][i]);

            dp[i][j] = max(dp[i][j], dp[i + 1][0]);
            dp[i][j] = max(dp[i][j], dp[i + 1][1]);
        }
    }
    cout << max(dp[0][0], dp[0][1]) << "\n";
    return 0;
}

