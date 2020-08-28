#include <bits/stdc++.h>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int n, m;
		cin >> n >> m;
		m *= 3600;
		
		int total = 0;
		for (int i = 0; i < n; i++) {
			int h1, m1, h2, m2;
			scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
			int seg1 = h1 * 3600 + m1 * 60;
			int seg2 = h2 * 3600 + m2 * 60;
			total += abs(seg2 - seg1);
		}
		cout << total << " " << m << endl;
		if (total >= m) {
			
			cout << "YES" << endl;}
			else cout << "NO" << endl;
		
	}
}
