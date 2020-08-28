#include <bits/stdc++.h>

using namespace std;

long long dp[10001][2][101];
const int mod = 1e9 + 7;

int main() {
    int m;
    string s;
    cin >> s >> m;

    int n = s.size(); 
    dp[n][1][0] = dp[n][0][0] = 1;
    for (int pos = n - 1; pos >= 0; pos--) 
        for (int flag = 0; flag < 2; ++flag) 
            for (int sum = 0; sum <= 100; ++sum) {
                int lim = flag ? s[pos] - '0' : 9;
                for (int i = 0; i <= lim; ++i) {
                    dp[pos][flag][sum] += dp[pos + 1][i == lim and flag][(sum + i) % m];
                    dp[pos][flag][sum] %= mod;
                }
            }

    cout << (dp[0][1][0] + mod - 1) % mod << "\n";

    return 0;
}

