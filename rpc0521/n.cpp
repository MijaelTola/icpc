#include<bits/stdc++.h> 

using namespace std;

int main() {
  
  int n;
  cin >> n;
  
  long long tot = 0;
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    v.push_back(x);
    tot += x;
  }
  
  for (int i = 0; i < n; ++i) {
    int x = v[i];
  	if(x == tot - x) return cout << x << "\n", 0;
  }
  cout << "BAD\n";
  return 0;
}

