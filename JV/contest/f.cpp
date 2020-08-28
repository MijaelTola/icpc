#include <iostream>
#include <climits>

using namespace std;

typedef unsigned long long ll;
int main(){
	
	ll n; cin >> n;
	ll a = -1; ll b =  1000000000LL;
	
	while(b - a > 1LL){
		ll mid = (a+b)/2LL;
		if((mid*(mid+1LL))/2LL >= n) b = mid;
		else a = mid;
	} 
	
	ll sec = (b*(b+1))/2LL;
	ll dif = sec - n;
	cout << b - dif<< "\n";
	return 0;
}
