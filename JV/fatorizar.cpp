#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int sieve[10001000];
vector<long long> v;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	for (int i = 2; i*i < 10001000; ++i){
		int c = i+i;
		while(c < 10001000){
			sieve[c] = -1;
			c+= i;
		} 
	}
	for (int i = 2; i < 10001000; ++i)
		if(sieve[i] == 0) v.push_back(i);
	
	unsigned long long n; 
	while(cin >> n){
		int pos = 0;
		int index = 0; unsigned long long pf = v[0];
		while(pf*pf <= n){
			while(n%pf == 0){
				cout <<  pf << " ";
				n/=pf;
			} 
			pf = v[++index];
		}
		if(n != 1) cout << n;
		cout << "\n";
	}
	return 0;
}
