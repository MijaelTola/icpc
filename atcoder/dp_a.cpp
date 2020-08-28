#include <bits/stdc++.h>

using namespace std;

int n;
int h[100010];
int dp[100010];

int main() {
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        dp[i] = 1e9;
    }
    
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 0; i < n; ++i) {
        if(i) dp[i] = min(dp[i], dp[i - 1] + abs(h[i - 1] - h[i]));
        if(i - 2 >= 0) dp[i] = min(dp[i], dp[i - 2] + abs(h[i - 2] - h[i]));
    }
    cout << dp[n - 1] << "\n";
    return 0;
}

