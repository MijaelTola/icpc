#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  
  long long total = 0;
  for (int &x: v) {
    cin >> x;
  	total += x;
  }
  
  sort(v.begin(), v.end());
  
  long long ans = 0;
  
  auto get = [](long long x) {
  	return x * (x + 1) / 2;
  };
  
  ans = max(0ll, total - get(n));
  
  for (int i = 0; i < n; ++i) {
    total -= v[i];
    ans = max(ans, total - get(n - i - 1));
  }
  cout << max(0ll,ans) << "\n";
  return 0;
}

