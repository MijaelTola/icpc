#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll occ[256];

int main() {
	string str;
	while(cin >> str) {
		memset(occ, 0LL, sizeof occ);
		for(int i = 0; i < str.size(); i++) {
			occ[str[i]]++;
		}
		ll minr = 1e15;
		ll X = -1;
		for(ll x = 2; x <= str.size(); x++) {
			ll par = 0;
			for(int i = 'a'; i <= 'z'; i++) {
				par = par + (occ[i] % x) * occ[i];
			}
			// cout << par << "\n";
			if(par < minr) {
				X = x;
				minr = par;
			}
		}
		cout << X << "\n";
	}
	return 0;
}