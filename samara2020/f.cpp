#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> ans;
  for (int i = 1; i <= n; i += 2)
    ans.push_back(i);
  if(ans.back() != n) ans.push_back(n);
  
  cout << ans.size() << "\n";
  for (int x: ans)
    cout << x << " ";
  cout << "\n";
  return 0;
}
