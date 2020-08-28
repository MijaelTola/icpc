#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  vector <int> a(4);
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  sort(a.begin(), a.end());
  if (a[0] == a[3]) {
    cout << "YES\n";
  }
  else if (a[0] == a[2] || a[1] == a[3]) {
    cout << "NO\n";
  }
  else if (a[0] == a[1] && a[2] == a[3]) {
    cout << "YES\n";
  }
  else if (a[1] == a[2]) {
    if (a[3] - a[2] == a[1] - a[0]) cout << "YES\n";
    else cout << "NO\n";
  }
  else if (a[1] == a[0] || a[2] == a[3]) {
    cout << "NO\n";
  }
  else {
    cout << "NO\n";
  }
  return 0;
}

