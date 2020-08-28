#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

typedef long long ll;
int val[310];
int dp[310][180100];
char sign[310];
int n;

int f(int pos, int sum){
	if(pos == n){
		if(sum == 0) return 0;
		else return 1e8;
	}
	if(dp[pos][sum+90000] != -1) return dp[pos][sum+90000];
	int ans = 1e8;
	if(sign[pos-1] == '+'){
		ans = min(ans,f(pos+1,sum+val[pos]));
		ans = min(ans,f(pos+1,sum-val[pos])+1);
	}else{
		ans = min(ans,f(pos+1,sum+val[pos])+1);
		ans = min(ans,f(pos+1,sum-val[pos]));
	}
	return dp[pos][sum+90000] = ans;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	for (int i = 0; i < 310; ++i)
		for (int j = 0; j < 180100; ++j)
			dp[i][j] = -1;
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
	if(sum == 0) return cout << 0 << "\n",0;
	int ans = f(1,val[0]);
	//cout  << ans << endl;
	if(ans == 1e8) cout << -1 << "\n";
	else cout << ans << "\n";
	return 0;
}
