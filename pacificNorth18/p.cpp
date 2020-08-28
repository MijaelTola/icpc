#include <bits/stdc++.h>
using namespace std;
const int lim = 1000000;

typedef long long ll;
bool Primes[lim + 10];
vector<int>P;
void primes() {
	for (int i = 2; i <= lim; i++) {
		if (!Primes[i]) {
			for (long long j = i + i; j <= lim; j+=i)Primes[j] = true;
		}
	}
	P.push_back(2);
	for (int i = 3; i <= lim; i += 2)if(!Primes[i])P.push_back(i);
}
ll _pow(ll base, ll p) {
	if (!p)return 1LL;
	if (p == 1)return base;
	ll res = _pow(base, p >> 1);
	res *= res;
	if (p % 2)res *=base;
	return res;
}
ll sumDiv(ll n) {
	ll pos = 0, PF = P[pos], ans = 1LL;
	while (PF * PF <= n) {
		ll power = 0LL;
		while (n  % PF == 0) n /= PF, power++;
		cout << PF << " " << power + 1 << endl;
		ans *= ((ll)_pow(PF, power + 1) - 1) / (PF - 1);
		cout << ans << endl;
		PF = P[++pos];
	}
	if (n != 1) ans *= ((ll)_pow(n , 2) - 1) / (n - 1);
	return ans;
}
int main() {
	primes();
	long long l, r;
	cin >> l >> r;
	ll ans = 0LL;
	while(l <= r){
		
		ans += sumDiv(l);
		
		l++;
	}
	cout << ans << "\n";
}
