#include <bits/stdc++.h>
using namespace std;
bool state[1010];
bool cstate[1010];
vector<int>G[2500];
int main() {
	int cnt = 0;
	int n, m;
	cin >> n >> m;
	int t; cin>>t;
	for (int i =0, pos;i<t;i++){
		cin >> pos;
		state[pos - 1]++;
		cnt++;
	}
	for (int i = 0, u, v; i < n;i++) {
		cin >> u;
		while (u--) {
			int t;cin>>t;
			G[i + m].push_back(t - 1);
		}
	}
}
