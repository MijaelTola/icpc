
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(0);
	int t;
  cin >> t;
  
  while(t--) {
    int a,b;
    cin >> a >> b;
    a -= b;
    if(a >= 10) cout << "YES\n";
    else cout << "NO\n";
    
  }
}

