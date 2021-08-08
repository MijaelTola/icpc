#include <bits/stdc++.h>

using namespace std;

int dp[500010];
int a[500010];

int main() {
    
    int n,k;
    cin >> n >> k;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[a[i]] = 1;
    }
    
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i - a[j] >= 0) 
                dp[i] |= !dp[i - a[j]];
        }
    }
    
    puts(dp[k] ? "First" : "Second");
    return 0;
}

