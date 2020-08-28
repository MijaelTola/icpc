#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
	if(b == 0) return a;
	return gcd(b,a%b);
}

ll LCM(ll a, ll b){
	return a*(b/gcd(a,b));
}

int main(){
	ll a,b; cin >> a >> b;
	
	cout << LCM(a,b);
	return 0;
}
