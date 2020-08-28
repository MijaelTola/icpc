#include <bits/stdc++.h>

using namespace std;

int dp[200100];

int f(int n){
    if(n == 1) return 1;
    int ans = (n / 2) + 1;
    for(int i = 1; i <= (n / 2); i++){
        if(n % i == 0){
            int dv = n / i;
            int m = (dv / 2) + 1;
            ans = min(ans, f(i) * m);
        }
    }
    return ans;
}

int main() {
    
    int n;
    cin >> n;
    
    cout << f(n) << "\n";
    return 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; ++i) {
        dp[i] = i / 2 + 1;
        for (int j = 1; j < i / 2; ++j) {
            if(i % j != 0) continue;
            int d = i / j;
            int m = (d / 2) + 1;
            dp[i] = min(dp[i], dp[j] * m);
        }
    }
    
    cout << dp[n] << "\n";
    return 0;
}

