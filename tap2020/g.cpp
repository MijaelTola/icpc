#include <bits/stdc++.h>


/*
 
    L - R
    1   0
    0   1
    0   1
    0   1

 * /
using namespace std;
 int main() {
   
   int ini = 100;
   int ans = ini;
   
   int n;
   cin >> n;
   
   for (int i = 0; i < n; ++i) {
     int x;
     cin >> x;
     ini += x;
     ans = max(ans, ini);
   }
   cout << ans << "\n";
  return 0;
}
