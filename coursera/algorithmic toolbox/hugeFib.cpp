#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int findPisanoperiod(int mod){
	if(mod == 1) return 1;
	int f0,fn2,f1,fn1;
	f0 = fn2 = 0;
	f1 = fn1 = 1;
	int period = 1;
	int fn;
	while(true){
		fn = (fn1+fn2)%mod;
		if(fn == f1 and fn1 == f0)
			return period;
		period++;
		fn2 = fn1;
		fn1 = fn;
	}
	return period;
}

int main(){
	
	ll n,m;
	cin >> n >> m;
	int pis = findPisanoperiod(m);
	ll a = 1;
	ll b = 0;
	ll c = 0;
	ll p = 0;
	n%=pis;
	while(p < n){
		c = (a + b)%m;
		a = b;
		b = c;
		p++;
	}
	cout << c << endl;
	return 0;
}
// 1 2 3 4  5  6
// 1 3 8 6 20 24
