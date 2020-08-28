#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <climits>

using namespace std;

typedef unsigned long long ll;
typedef pair<int,int> ii;

#define F first
#define S second
#define pb push_back
#define FOR(i,n,m) for (int i = n, i < m; ++i)
#define rep(i,n,m) FOR(i,n,m)

const int MAXN = INT_MAX;

set<ll> f;
vector<ll> v;

int st[2*100010];
int n;
void update(int pos,int value){
	for (st[pos+=n]=value; pos>1; pos>>=1)
		st[pos>>1] = st[pos] + st[pos^1];
}

int q(int l, int r){
	int ans = 0;
	for (l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1) ans += st[l++];
		if(r&1) ans += st[--r];
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	ll a = 0;
	ll b = 1;

	ll c = 0;
	for (int i = 0; i < 93; i++){
	// 		cout << c << endl;
		v.push_back(c);
		a = b;
		b = c;
		c = a+b;
	}
//	cout << endl;
	for (int i = 0; i < v.size(); ++i)
		for (int j = 0; j < v.size(); ++j){
			if(i == j) continue;
			f.insert(v[i]+v[j]);
		}
	
//for (ll r: f) cout << r << endl;
	int s; cin >> n >> s;
	for (int i = 0; i < n; ++i){
		ll x; cin >> x;
		update(i,f.count(x));
	}
	while(s--){
		int c; cin >> c;
		if(c == 1){
			int x,y; cin >> x >> y;
			x--;
			cout << q(x,y) << "\n";
		}else{
				int x; ll y; cin >> x >> y;
				x--;
				update(x,f.count(y));
		}
	}
	return 0;
}
