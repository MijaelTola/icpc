#include <bits/stdc++.h>

using namespace std;

int in[200010];

int main() {
	int n;
  	cin >> n;
  
  	for (int i = 0; i < n - 1; ++i) {
      	int x,y;
      	cin >> x >> y;
      	in[x]++, in[y]++;
    }
  
  	int cnt = 0;
  
  	for (int i = 1; i <= n; ++i) {
      	cnt += in[i] == 1;
    }
  
  	cout << cnt / 2 + (cnt & 1) << "\n";
	return 0;
}
