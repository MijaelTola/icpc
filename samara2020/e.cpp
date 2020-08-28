#include <bits/stdc++.h>

using namespace std;

int main() {
  
  int n;
  cin >> n;
  vector<int> v(n);
  
  long long ans = LLONG_MAX;
  long long sum = 0;
  for (int &x: v) {
    cin >> x;
    sum += x;
    ans = min(ans, sum);
  }
  
  if(ans >= 0) return cout << 0 << "\n", 0;
  else cout << -ans << "\n";
  
  
  return 0;
}
