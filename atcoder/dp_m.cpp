#include <bits/stdc++.h>

using namespace std;

long long v[110];
long long dp[110][100010];
long long prefix[110][100010];
const int mod = 1e9 + 7;

int main() {
    
    int n,k;
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", v + i);
    
    for (int i = 0; i <= n; ++i)
        dp[i][0] = prefix[i][0] = 1;

    for (int i = 0; i <= k; ++i)
        prefix[0][i] = 1;
    
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j) {
        dp[i][j] += (prefix[i - 1][j] - (j - v[i] - 1 >= 0 ? prefix[i - 1][j - v[i] - 1] : 0) + mod) % mod;
            dp[i][j] %= mod;
            prefix[i][j] = prefix[i][j - 1] + dp[i][j];
            prefix[i][j] %= mod;
        }
   

    printf("%lld\n", dp[n][k]);
    return 0;
}

