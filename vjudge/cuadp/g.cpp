#include <bits/stdc++.h>

using namespace std;

long long v[100010];
long long dp[100010];

int main() {
    
    int n;
    cin >> n;


    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v[x]++;
    }

    for (int i = 100000; i >= 0; i--) {
        dp[i] = max(dp[i], dp[i + 1]);
        dp[i] = max(dp[i], dp[i + 2] + i * v[i]);
    }

    cout << dp[0] << "\n";


    return 0;
}

