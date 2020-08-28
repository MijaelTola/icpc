#include <bits/stdc++.h>

using namespace std;

bool v[22];
int main() {
	memset(v,0,sizeof v);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			v[i] = x;
		}
		
		int ans = 0;
		for (int i = 0; i < n; ++i) 
			ans += (v[i] != 0);
			
		cout << ans << "\n";
	}
	return 0;
}
