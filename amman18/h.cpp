#include <bits/stdc++.h>
using namespace std;
int n;
int v[2 * 1010];
int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int cases;
	cin >> cases;
	while (cases--) {
		int n;
		cin >> n;
		for (int i = 0; i < 2 * n;i++)cin >>v[i];
		int ans = 0;
		for (int i = 0, j = 2 * n - 1; i < n; i++,j--)ans = max(ans, v[i] + v[j]);
		cout << ans << "\n";
	}
	return 0;
}

