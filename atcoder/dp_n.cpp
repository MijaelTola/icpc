#include <bits/stdc++.h>

using namespace std;


int n;
int dp[500][500];
int a[500];
int p[500];

int main() {
    memset(dp, 30, sizeof dp);

    cin >> n;

    for (int i = 0; i < n; i ++)
        cin >> a[i];

    for (int i = 0; i < n; i ++)
        p[i + 1] = p[i] + a[i];

    for (int i = 0; i < n; i ++)
        dp[i][i + 1] = 0;

    for (int j = 1; j <= n; j ++)
        for (int i = j - 2; i >= 0; i --)
            for (int k = i; k < j; k ++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + p[j] - p[i]);

    cout << dp[0][n] << "\n";

    return 0;
}
