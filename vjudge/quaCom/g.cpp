#include <bits/stdc++.h>

using namespace std;

long long dp[20][2][5];

long long f(string s) {
    memset(dp, 0, sizeof dp);
    int n = s.size();

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 4; ++j)
            dp[n][i][j] = 1;

    for (int pos = n - 1; pos >= 0; pos--) 
        for (int flag = 0; flag < 2; ++flag) 
            for (int sum = 0; sum <= 3; ++sum) {
                int lim = flag ? s[pos] - '0' : 9;
                for (int i = 0; i <= lim; ++i){
                    if(sum + (i != 0) <= 3)
                        dp[pos][flag][sum] += dp[pos + 1][i == lim and flag][sum + (i != 0)];
                }
            }

    return dp[0][1][0];
}

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        long long l,r;
        cin >> l >> r;
        cout << f(to_string(r)) - f(to_string(l - 1))  << "\n";
    }
    return 0;
}

