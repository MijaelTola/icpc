#include <bits/stdc++.h>
 
using namespace std;
 
int n,k;
long long  m[4010][4010];
long long dp[4010][4010];
long long h[4010], w[4010];
 
long long cost(int i, int j) {
    return m[min(i, j)][max(i,j)] * (w[j] - w[i - 1]);
}
 
void compute(int g, int i, int j, int l, int r) {
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
    
    compute(g,i, mid - 1, l, bestIndex);
    compute(g, mid + 1, j, bestIndex, r);
}
 
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for (int i = 0; i < 4010; ++i)
        for (int j = 0; j< 4010; ++j)
            dp[i][j] = 1e17;
 
    cin >> n >> k;
  	
  	for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> h[i];
    }
  	
    for (int i = 1; i <= n; ++i) {
      	long long cur = 0;
        for (int j = i; j <= n; ++j) {
          cur = max(cur, h[j]);
          m[i][j] = cur;
        }
    }
  
    
  	for (int i = 1; i <= n; ++i)
      w[i] += w[i - 1];
    
    dp[n + 1][0] = 0;
    for (int i = n; i >= 1; i--) {
        for (int l = 0; l <= k; ++l) {
            for (int j = i; j <= n; ++j) {
                auto &ans = dp[i][l] = 1e17;
                if(l)ans = min(ans, dp[j + 1][l - 1] + cost(i,j));
            }
        }
    }

   

 
    cout << dp[1][k] << "\n";

    return 0;
}
