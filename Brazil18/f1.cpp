#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>, pair<int,int> > > v;
int n; 
int memo[1010][1300];

int bs(int pos) {
    int a = pos;
    int b = n - 1;
    int x = v[pos].first.second;
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(v[mid].first.first >= x) b = mid;
        else a = mid;
    }
    return b;
}

int f(int pos, int mask) {
	if(pos == n) {
		if(__builtin_popcount(mask) == n) return 0;
		return -1e9;
	}
	if(__builtin_popcount(mask) == n) return 0;
	if(memo[pos][mask] != -1) return memo[pos][mask];
	int ans = -1e9;
    int pp = bs(pos);
	for (int i = pp; i < (int)v.size(); ++i) {
		int fin = v[pos].first.second;
		int ini = v[i].first.first;
		int p = v[i].second.second;
		int cost = v[i].second.first;
		if(ini >= fin) {
			int dp = f(i,(mask | (1 << p)));
			ans = max(ans,dp + cost);
		}
	}
	
	return memo[pos][mask] = ans;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(memo, -1, sizeof memo);
	cin >> n;
	v.push_back({{0,0},{0,0}});
	for (int i = 0; i < n; ++i) {
		int c; cin >> c;
		for (int j = 0; j < c; ++j) {
			int x,y,costo;
			cin >> x >> y >> costo;
			v.push_back({{x,y},{costo,i}});
		}
	}
	
	sort(v.begin(),v.end());
	int ans = f(0,0);
	if(ans < 0) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}
