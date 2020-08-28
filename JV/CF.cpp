#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main(){
	int m,k,n;
	cin >> m >> k >> n;
	vector<ll> v[102];
	ll l[10010];
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < k; ++j){
			ll x; cin >> x; v[i].push_back(x);
		}
			

	for (int i = 0; i < n; ++i){
		ll x; cin >> x; l[i]= x;
	}
		
	
	sort(l,l+n);
	int ans = m;
	for (int i = 0; i < m; ++i)
	{
		bool sw = false;
		for (int j = 0; j < v[i].size(); ++j){
			ll a = -1; int b = n;
			ll c = v[i][j];
			while(b - a > 1){
				ll mid = (a+b) >> 1;
				if(l[mid] > c) b = mid;
				else a = mid;
			}
			if( a==-1  || l[a] != c= ){
				sw = true; break;
			}
		}
		if(sw)	ans--;
	}
	cout << ans;
	return 0;
}
