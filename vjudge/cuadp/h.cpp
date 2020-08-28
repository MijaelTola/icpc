#include <bits/stdc++.h>

using namespace std;

int n,k;
int a[110];
int b[110];
int dp[110][200010];

int mid = 100000;

int main() {
    
    for (int i = 0; i < 110; ++i)
        for (int j = 0; j < 200010; ++j)
            dp[i][j] = -1e9;

    cin >> n >> k;


    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        cin >> b[i];
    
    dp[n][mid] = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 200010; ++j) {
            int val = j - mid;
            dp[i][j] = max(dp[i][j], dp[i + 1][val + mid]);
            dp[i][j] = max(dp[i][j], dp[i + 1][(val + a[i] - k * b[i]) + mid] + a[i]);
        }
    }
    
    if(dp[0][mid] <= 0) cout << "-1\n";
    else cout << dp[0][mid] <<"\n";
    
    return 0;
}

