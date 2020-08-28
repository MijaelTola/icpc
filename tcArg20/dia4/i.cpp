#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int dp[1000010][3];

int main() {

    int n;
    cin >> n;
    

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 2; ++j) {

            if(j == 0 and i & 1) 
                dp[i][j] +=  dp[i + 1][1] + 1;

            if(j == 1 and i % 2 == 0)
                dp[i][j] += dp[i + 1][0] + 1;

            dp[i][j] += dp[i + 1][j];
            dp[i][j] %= mod;
        }
    }
   
    cout << (dp[0][0] + dp[0][1]) % mod << "\n";
    return 0;
}

