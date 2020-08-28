
#include <bits/stdc++.h>

using namespace std;

vector<int> G[65];
int main() {
	int n; cin >> n;
	cout << n << endl;
	
	for (int i = 0; i < n - 1; ++i) {
		int x,y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	for (int i = 1; i <= n; ++i) {
		cout << G[i].size() << " ";
		for (int v: G[i]) {
			cout << v << " ";
		}
		cout << "\n";
	}
}
