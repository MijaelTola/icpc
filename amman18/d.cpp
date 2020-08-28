#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int cases;
	cin >> cases;
	while (cases--) {
		long long n, m;
		cin >> n >> m;
		if(m > n) swap(n,m);
		n++;
		long long x = (m + 1) / 2;
		long long y = m - x;
		long long l = (n + 1) / 2;
		long long l2 = n - l;
		cout << min(x * l + y * l2, y * l + x * l2) << "\n";
	}
	return 0;
}
