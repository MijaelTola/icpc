#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;


ll v[1010];
int l[1010];
int ld[1010];

int lis(int n){
	int ans = -1;
	for (int i = 0; i < 1010; ++i)
		l[i] = 1;
	for (int i = 1; i < n; ++i)
		for  (int j = 0; j < i;++j){
			if(v[i] > v[j] and l[i] < l[j]+1)
				l[i] = l[j]+1;
		}

	for (int i = 0; i < n; ++i)
		ans = max(l[i],ans);
		
	return ans;
}
int lds(int n){
	int ans = -1;
	for omo lo hago yo(int i = 0; i < 1010; ++i)
		ld[i] = 1;
	for (int i = n-1; i >= 1; --i)
		for  (int j = i+1; j < n;++j){
			if(v[i] > v[j] and ld[i] < ld[j]+1)
				ld[i] = ld[j]+1;
		}

	for (int i = n-1; i >= 0; --i)
		ans = max(ans,ld[i]);
	return ans;
}
int  main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	
	for (int i = 0; i < n; ++i)	cin >> v[i];
	int p = lis(n); int r = lds(n);
	
	int ans = -1;
	bool flag = false;
	for (int i = 0; i < n; ++i){
		int sum = 0;
		for (int j = i+1; j < n; ++j){
			if(v[i] > v[j]){
				sum = l[i]+ld[j];
				flag = true;
			}
			ans = max(sum,ans);
		}
	}
	if(!flag) cout << p << "\n";
	else cout << ans << "\n";
	return 0;
}
