#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

typedef long long ll;
ll val[25];
char sign[25];
int n;
ll f(int pos, ll sum, int c){
	if(pos == n){
		if(sum == 0) return c;
		else return INT_MAX;
	}
	ll ans = INT_MAX;
	
	if(sign[pos-1] == '+'){
		ans = min(ans,f(pos+1,sum+val[pos],c));
		ans = min(ans,f(pos+1,sum-val[pos],c+1));
	}else{
		ans = min(ans,f(pos+1,sum+val[pos],c+1));
		ans = min(ans,f(pos+1,sum-val[pos],c));
	}
	return ans;
}
int main(){
	cin >> n;
	int sum;
	cin >> sum;
	val[0] = sum;
	for (int i = 1; i < n; ++i){
		char s; int x;
		cin >> s >> x;
		if(s == '+') sum += x;
		else sum -= x;
		val[i] = x;
		sign[i-1] = s;
	}
	ll ans = f(1,val[0],0);
	if(ans == INT_MAX) cout << -1 << "\n";
	else cout << ans << "\n";
	return 0;
}
