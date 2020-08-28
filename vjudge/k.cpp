#include <bits/stdc++.h>

using namespace std;

int n,dk;
const int mod = 1e9 + 7;
long long dp[2][202][1010];
int v[210];
int b[210];

int main() {

    cin >> n >> dk;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    sort(v, v + n);
    for (int i = 1; i < n; ++i) 
        b[i] = v[i] - v[i - 1];

    for (int i = 0; i <= dk; ++i)
        dp[0][0][i] = 1;

    int last = 0;
    for (int i = n - 1; i >= 0; i--) {
        int cur = 1 - last;
        for (int j = 0; j <= 200; ++j) 
            for (int k = 0; k <= dk; ++k) 
                dp[cur][j][k] = 0;
        for (int j = 0; j <= 200; ++j) {
            for (int k = 0; k <= dk; ++k) {
                int add = k + b[i] * j;
                if(add <= dk) {
                    //add to some
                    dp[cur][j][k] += dp[last][j][add] * j;
                    dp[cur][j][k] %= mod;
                    //new 
                    dp[cur][j][k] += dp[last][j + 1][add];
                    dp[cur][j][k] %= mod;
                    //fin
                    if(j) dp[cur][j][k] += dp[last][j - 1][add] * j;
                    dp[cur][j][k] %= mod;
                    //self
                    dp[cur][j][k] += dp[last][j][add];
                    dp[cur][j][k] %= mod;
                    
                }
            }
        }
        last = cur;
    }
    
    cout << dp[last][0][0] << "\n";

    return 0;
}


