#include <bits/stdc++.h>

using namespace std;

int dp[1010][3];

int main() {

    string s;
    cin >> s;

    int n = s.size() - 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 3; ++j) {
            int val = s[i] - '0';
            int sum = ((j * 10) % 3 + val) % 3;
            dp[i][j] = max(dp[i][j], dp[i + 1][sum % 3] + (sum == 0));
            dp[i][j] = max(dp[i][j], dp[i + 1][0]);
        }
    }

    cout << dp[0][0] << "\n";
    return 0;
}

