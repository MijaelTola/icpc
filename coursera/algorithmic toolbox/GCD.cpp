#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
	if(b == 0) return a;
	return gcd(b,a%b);
}

int main(){
	
	ll a,b; cin >> a >> b;
	cout << gcd(a,b);
	return 0;
}
