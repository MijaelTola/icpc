#include <bits/stdc++.h>

using namespace std;

long long dp[2010];
long long h[2010];
long long w[2010];
int n,dk;

long long f(int pos, int k) {
    if(pos == n) {
        if(k == 0) return 0;
        return 1e17;
    }

    
    if(dp[pos + k] != -1) return dp[pos + k];
    long long ans = 1e17;
    long long a = 0, b = 0;

    for (int i = pos; i < n; ++i) {
        a += w[i];
        b = max(b, h[i]);
        if(k > 1) ans = min(ans, f(i + 1, k - 1) + a * b);
    }
    
    if(k == 1) ans = min(ans, f(n, k - 1) + a * b);

    return dp[pos + k] =  ans;
}

int main() {

    memset(dp, -1, sizeof dp);

    cin >> n >> dk;

    for (int i = 0; i < n; ++i)  {
        cin >> w[i] >> h[i];
    }

    cout << f(0, dk) << "\n";

    return 0;
}
