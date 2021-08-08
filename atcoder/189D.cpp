#include <bits/stdc++.h>

using namespace std;

long long dp[61][2];

int main() {
    
    int n;
    cin >> n;
    vector<string> v;

    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        v.push_back(x);
    }
    
    dp[n][1] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 2; ++j) {
            if(v[i] == "AND") {
                dp[i][j] += dp[i + 1][j & 1];
                dp[i][j] += dp[i + 1][j & 0];
            } else {
                dp[i][j] += dp[i + 1][j | 1];
                dp[i][j] += dp[i + 1][j | 0];
            }

        }
    }

    cout << dp[0][0] + dp[0][1] << "\n";
    return 0;
}

