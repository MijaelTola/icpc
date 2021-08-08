#include <bits/stdc++.h>

using namespace std;

int dp[20][3][2];

int main() {
 

    for (int i = 0; i < 20; ++i) {
        for (int k = 0; k < 3; ++k) {
            dp[i][k][0] = dp[i][k][1] = 1e9;
        }
    }
    long long n;
    cin >> n;

    string s = to_string(n);
    int sz = s.size();
    
    dp[sz][0][1] = 0;

    for (int i = sz - 1; i >= 0; i--) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 2; ++k) {
                int val = s[i] - '0';
                int &ans = dp[i][j][k] = 1e9;
                ans = min(ans, dp[i + 1][j][k] + 1);
                ans = min(ans, dp[i + 1][(j + val) % 3][1]);
            }
        }
    }

    if(dp[0][0][0] == 1e9) return cout << "-1\n", 0;
    cout << dp[0][0][0] << "\n";
    return 0;
}

