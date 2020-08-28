#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ll;
int main(){
	int n;
	cin >> n;
	ll a = 1;
	ll b = 0;
	ll c = 0;
	ll p = 1;
	while(p <= n){
		c = (a + b)%10;
		a = b;
		b = c;
		p++;
	}
	cout << c << endl;
	//cout << c%10 << endl;
	return 0;
}

//1234 / 10 123
