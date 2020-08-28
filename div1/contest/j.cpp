#include <bits/stdc++.h>
using namespace std;

int cnt[10010];
int main() {
	int caes;
	cin >> caes;
	int n;
	while (caes--) {
		cin >> n;
		memset(cnt, 0, sizeof cnt);
		for (int i = 0, u; i < n; i++) {
			cin >> u;
			cnt[u]++;
		}
		int maxi = 0;
		for (int i = 1; i <=  10000; i++) {
			maxi = max(maxi, cnt[i] + cnt[i - 1]);
		}
		cout << maxi << endl;
	}
}
