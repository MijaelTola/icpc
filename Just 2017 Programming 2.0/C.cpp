#include <bits/stdc++.h>
#define ii pair <int, int>
using namespace std;

const int N = 1e4 + 10;
const int inf = 1 << 30;

int msk[N];

vector <ii> adj[N];

int cost(int u, int v) {
	return __builtin_popcount(msk[u] & msk[v]);
}

int main() {
	int n, m;
	string str;
	while (cin >> n >> m) {
		memset(msk, 0, sizeof msk);
		for (int i = 0; i < n; i++) {
			cin >> str;
			for (int j = 0; j < str.size(); j++) {
				if (str[j] <= 'Z' && str[j] >= 'A') str[j] = str[j] xor 32;
				int z = str[j] - 'a';
				msk[i] = msk[i] | (1 << z);
			}
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			adj[u].push_back(ii(v, cost(u, v)));
			adj[v].push_back(ii(u, cost(u, v)));
		}
		int s, e;
		cin >> s >> e;
		s--, e--;
		priority_queue <ii, vector <ii>, greater<ii> > q;
		q.push(ii(0, s));
		vector <int> dist(N, inf);
		dist[s] = 0;
		while (!q.empty()) {
			ii temp = q.top();
			q.pop();
			int w = temp.first;
			int u = temp.second;
			if (dist[u] < w) {
				continue;
			}
			for (auto x : adj[u]) {
				int v = x.first;
				int c = x.second;
				if (dist[u] + c < dist[v]) {
					dist[v] = dist[u] + c;
					q.push(ii(dist[u] + c, v));
				}
			}
		}
		cout << dist[e] << '\n';
	}
	return 0;
}