
#include <bits/stdc++.h>

using namespace std;

int v[1010];

int main() {
  
  int a,b,c;
  cin >> a >> b >> c;
  
  for (int i = 1; i <= a; ++i)
  	v[i] = i % c == 0 or i % b == 0;
  
  int ans = 0;
  for (int i = 1; i < a; ++i) {
		ans += v[i];
  }
  
  cout << ans << "\n";
  return 0;
}

