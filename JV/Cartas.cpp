#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int v[1010];
int dp[1010][1010][2];
int n;

int f(int left,int right, bool turn){
	if(left == right) return 0;
	if(dp[left][right][turn] != -1) return dp[left][right][turn];
	int ans = -1;
	if(turn){
		ans = max(ans,f(left+1,right,false)+v[left]);
		ans = max(ans,f(left,right-1,false)+v[right]);
	}else{
		if(v[left] >= v[right]) return f(left+1,right,true);
		else return f(left,right-1,true);
	}
	return dp[left][right][turn] = ans;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int k = 0;
	while(cin >> n and n){
	memset(dp,-1,sizeof dp);
	int total = 0;
	for (int i = 0; i < n; ++i){
		cin >> v[i];
		total += v[i];
	}	
	
	int A = f(0,n-1,true);
	int B = total - A;
	int ans = A - B;
	//cout << total << " " << A << " " << B<< endl;
	cout <<"En el juego "<< ++k<<", la estrategia greedy pierde por "<< ans << " puntos.\n";
	}
	return 0;
}
