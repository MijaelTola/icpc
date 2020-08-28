#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	ll a = 1LL, b = 1LL;
	while(n--){
		a*=4;
		b*=2;
	}
	
	cout<<(a * b)<<'\n';
	
	
	return 0;
}
//print(8**raw_input())
