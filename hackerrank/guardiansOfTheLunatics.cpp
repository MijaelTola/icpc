#include <bits/stdc++.h>

using namespace std;

long long l[8010];
long long dp[8010][810];

long long cost(long long i, long long j) {
    return (j - i + 1) * (l[j] - l[i - 1]);
}

void f(int g, int i, int j, int l, int r) {
    if(i > j) return;

    int mid = (i + j) / 2;
    int bestIndex = l;

    for (int k = l; k <= min(r, mid); ++k) {
        long long val = dp[k - 1][g - 1] + cost(k, mid);
        if(val < dp[mid][g]) {
            dp[mid][g] = val;
            bestIndex = k;
        }
    }
    
    f(g,i, mid - 1, l, bestIndex);
    f(g, mid + 1, j, bestIndex, r);
}

int main() {

    int n, k;
    for (int i = 0; i < 8010; ++i)
        for (int j = 0; j < 810; ++j)
            dp[i][j] = 4e18;

    cin >> n >> k;
    
    k = min(n, k);
    for (int i = 1 ; i <= n; ++i)
        cin >> l[i];

    for (int i = 1; i <= n; ++i)
        l[i] += l[i - 1];
        
    dp[0][0] = 0;

    for (int i = 1; i <= k; ++i)
        f(i, 1, n, 1, n);

    cout << dp[n][k] << "\n"; 

    return 0;
}

