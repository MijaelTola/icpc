#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 9;
long long dp[310];

int n,k;
int f(int n) {
  dp[0] = dp[1] = 1;
  for (int i = 2; i <= n + 2; ++i) {
    dp[i] = 0;
    for (int j = 0; j < i; ++j) {
      dp[i] += (dp[j] * dp[i - j - 1]) % mod;
      dp[i] %= mod;
    }
  }
  return dp[n - 2];
}

int main() {
    cin >> n >> k;
    if(n == 3 and k == 0) return cout << "0\n", 0;
    if(k != n - 2 and k != 0) cout << "0\n";
    else if(k == 0) cout << "1\n";
    else cout << f(n) << "\n";
    return 0;
}
