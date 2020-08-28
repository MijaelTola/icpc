#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

typedef long long ll;
int v[100010];
ll go[100010];
ll back[100010];
int n; 

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin>>v[i];
	
	ll sum = 0;
	ll ans = 0;
	for (int i = 0; i < n; ++i){
		sum += v[i];
		sum = max(sum,0LL);
		ans = max(ans,sum);
		go[i] = ans;
	}
	sum = 0;
	ll ans1 = 0;
	for (int i = n-1; i >= 0; --i){
		sum += v[i];
		sum = max(sum,0LL);
		ans1 = max(ans1,sum);
		back[i] = ans1;
	}
	ans = 0;
	for (int i = 0; i < n-1; ++i){
		ll a = go[i] + back[i+1];
		ans = max(a,ans);
	}
	cout << ans << "\n";
	return 0;
}
