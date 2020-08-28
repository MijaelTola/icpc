#include <iostream>
#include <queue>
#include <set>
#include <cstring>
#include <climits>

using namespace std;

string v[110],x;
int dp[10000];
int n;o
int f(int sz){
	if(sz == x.size()) return 0;
	if(sz > x.size()) return 1e7;
	if(dp[sz] != -1) return dp[sz];
	int ans = 1e7;
	for (int i = 0; i < n;++i){
		int d = 0;
		for (int j = 0; j < v[i].size(); ++j)
			if(x[j+sz] != v[i][j]) d++;
		ans = min(ans,f(v[i].size()+sz)+d);
	}
	return dp[sz] = ans;
}
int main(){
	
	memset(dp,-1,sizeof dp);
	cin >> x >> n;	
	for (int i = 0; i < n; ++i) cin >> v[i];
	
	int ans = 1e7;
	
	for (int i = 0; i < n; ++i){
		int d = 0;
		for (int j = 0; j < v[i].size(); ++j)
			if(x[j] != v[i][j])d++;
		ans = min(ans,f(v[i].size())+d);
	}
	
	if(ans == 1e7) cout << -1 << endl;
	else cout << ans << endl;
}
