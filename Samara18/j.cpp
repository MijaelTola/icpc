#include <bits/stdc++.h>

using namespace std;

int c[200010];
int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	
	int n; cin >> n;
	
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		c[x]++;
	}
	
	int ans = 0;
	int cur = 0;
	for (int i = 0; i < 200010; ++i) {
		cur += c[i] / 2;
		c[i] %= 2;
	}
	ans += cur / 2;
	
	cout << ans << "\n";
	
	
}
