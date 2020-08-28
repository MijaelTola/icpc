#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
bool cmp(const pair<ll,ll> a, const pair<ll,ll> b){
	if(a.second == b.second) return a.first > b.first; 
	return a.second < b.second;
}
vector<pair<ll,ll> > v;
int main(){
	int n;
	while(cin >> n){
		v.clear();
		for (int i = 0; i < n; ++i){
			ll x,y; cin >> x >> y;
			v.push_back({x,y});
		}
		sort(v.begin(),v.end(),cmp);
		ll ans = 0;
		ll last = -1;
		for (int i = 0; i < n; ++i){
			if(v[i].first > last){
				ans++;
				last = v[i].second;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
