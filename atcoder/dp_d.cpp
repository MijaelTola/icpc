#include <bits/stdc++.h>

using namespace std;

int v[110][2];
long long dp[110][100010];
int n,w;

int main() {
    cin >> n >> w;

    for (int i = 1; i <= n; ++i) 
        cin >> v[i][0] >> v[i][1];

    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= w; ++j) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if(j - v[i][0] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i][0]] + v[i][1]);
        }
    }
    cout << dp[n][w] << "\n";
    return 0;
}

