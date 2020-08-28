#include <bits/stdc++.h>

using namespace std;

int main(){

	long long x,z,t;
	cin >> t;
	while(t--){
		cin >> x >> z;
		long long ans2 = x ^ z;
		long long ans3 = x & z;
		long long a,b,c;
		a = ans2;
		if((x | ans2) == z)	b = ans2;
		else b = -1;
		if((x & ans3) == z) c = ans3;
		else c = -1;
		cout << a << " " << b << " " << c << endl;
	}
	return 0;
}