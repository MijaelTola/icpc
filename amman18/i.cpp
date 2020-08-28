#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int cases;
	cin >> cases;
	while (cases--) {
		int n, k;
		cin >> n >> k;
		if (k > n)cout << "-1\n";
		else {
			vector<int>ans;
			while (k > 0) {
			//	cout << " MY K " << k << endl;
				int u = n / k;
				ans.push_back(u);
				n -= u;
				k--;
			}
			sort(ans.begin(), ans.end());
			for (int i = 0; i < ans.size();i++){if (i) cout << " ";cout << ans[i];}
			cout << "\n";
		}
	}
	return 0;
}

