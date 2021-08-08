#include <bits/stdc++.h>

using namespace std;

int v[10010][3];
int dp[10010][110];

int main() {

    int t;
    cin >> t;

    while(t--) {

        ios::sync_with_stdio(false); cin.tie(0);
        int n,k;
        cin >> n >> k;

        for (int i = 0; i < n; ++i) 
            cin >> v[i][0] >> v[i][1] >> v[i][2];

        for (int i = n; i >= 0; i--) {
            for (int j = 109; j >= 0; j--) {
                int &ans = dp[i][j] = -1e9;
                if(i == n) {
                    if(j >= k) ans = 0;
                    continue;
                }
                ans = max(ans, dp[i + 1][min(k, j + v[i][0])]);
                ans = max(ans, dp[i + 1][j] + v[i][1]);
                ans = max(ans, dp[i + 1][j] + v[i][2]);
            }
        }
        
        if(dp[0][0] >= 0) cout << dp[0][0] << "\n";
        else cout << "NO SOLUTION\n";

    }
    return 0;
}

