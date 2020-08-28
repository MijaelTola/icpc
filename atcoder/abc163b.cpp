#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,m;
  cin >> n >> m;
  long long sum = 0;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    sum += x;
  }
 	
  cout << max(-1ll, n - sum) << "\n";
  return 0;
}
