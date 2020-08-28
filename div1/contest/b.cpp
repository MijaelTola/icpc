#include <bits/stdc++.h>
using namespace std;
int v[10010];
char s[10010];
vector<int>match, vis, G[10010];
int dfs(int l) {
	if (vis[l])return 0;
	vis[l] = 1;
	for (int r: G[l]) {
		if (match[r] == -1 || dfs(match[r])) {
			match[r] = l; return 1;
		}
	}
	return 0;
}
int p[1000010];
int main() {
	for (int i = 2; i * i <= 1000000; i++) {
		if (!p[i]) {
		for (int j = i * i; j <= 1000000; j+= i) {
				p[j] = true;
			}
		}
	}
	ios::sync_with_stdio(false);cin.tie(0);
	int cases;
	cin >> cases;
	while (cases--) {
		int n;
		cin >> n;
		vector<int>m,f;
		for (int i = 0; i < 10010; i++)G[i].clear();
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		int primes = 0;
		for (int i = 0; i < n; i++) {
			// if (!p[i]) {primes++;continue;}
			if (s[i] == 'F') {
				f.push_back(v[i]);
			} else {
				m.push_back(v[i]);
			}
		}
		for (int i = 0; i < m.size(); i++) {
			for (int j = 0; j < f.size(); j++) {
				if (__gcd(m[i], f[j])) {
					G[i].push_back(j + m.size());
				}
			}
		}
		match.assign(m.size() + f.size() + 10, -1);
		int MCBM = 0;
		for (int i = 0; i < m.size(); i++) {
			vis.assign(m.size(), 0);
			MCBM += dfs(i);
		}
		cout << MCBM + primes + (m.size() - MCBM) + (f.size() - MCBM) << "\n";
	}
}
