#include <bits/stdc++.h>

using namespace std;

int n,k;
int v[100010];
int dp[100010];

int main() {
    
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        dp[i] = 1e9;
    }
    
    dp[0] = 0;
    
    for (int i = 0; i < n; ++i) 
        for (int j = i - 1, dk = k; j >= 0 and dk; j--, dk--) 
            dp[i] = min(dp[i], dp[j] + abs(v[i] - v[j]));
        
    cout << dp[n - 1] << "\n";
    return 0;
}

