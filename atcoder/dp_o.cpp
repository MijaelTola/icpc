#include <bits/stdc++.h>

using namespace std;

bool v[22][22];
int dp[22][1 << 22];
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            cin >> v[i][j];
    
    dp[n][(1 << n) - 1] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < (1 << n) - 1; j++) {
            if(__builtin_popcount(j) != i) continue;
            for (int k = 0; k < n; ++k) {
                if(!(j & (1 << k)) and v[i][k]) {
                   dp[i][j] += dp[i + 1][j | (1 << k)]; 
                   dp[i][j] %= mod;
                }
            }
        }
    }

    cout << dp[0][0] << "\n";
            
    return 0;
}

