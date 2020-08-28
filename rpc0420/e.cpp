#include <bits/stdc++.h>

using namespace std;

int a[28];
long long dp[30];
const int mod = 11092019;

int main() {
	string s;
  cin >> s;
  
  for (auto x: s)
    a[x - 'a']++;
  
  dp[27] = 1;
  for (int i = 26; i >= 0; i--) {
  	dp[i] += dp[i + 1] * a[i];
    dp[i] %= mod;
    dp[i] += dp[i + 1];
    dp[i] %= mod;
  }
  cout << dp[0] << "\n";
  return 0;
}

