#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;
const int N = 1e5 + 10;

long long fact[N], invfact[N];

long long power(long long a, long long b) {
	long long ans = 1;
	while (b > 0) {
		if (b & 1LL) ans = (ans * a) % md;
		b >>= 1LL;
		a = (a * a) % md;
	}
	return ans;
}

long long inv(long long a) {
	return power(a, md - 2);
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int n, m, k;
	double p;
	fact[0] = invfact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = (fact[i - 1] * i) % md; 
		invfact[i] = inv(fact[i]);
	}
	while (cin >> m >> n >> k >> p) {
		int z = (int)(p * 1000.0 + 1e-10);
		int deb = inv(1000);
		//cout << z << ' ' << deb << endl;
		int P = (1LL * z * deb) % md;
		//cout << P << endl;
		int MP = (1 - P + md) % md;
		//cout << MP << endl;
		//cout << n << ' ' << n - k << endl;
		//cout << (power(P, k) * power(MP, n - k)) % md << endl;
		if (n >= k && n <= m) {
			cout << ((fact[n - 1] * (invfact[k - 1] * invfact[n - k]) % md) % md * (power(P, k) * power(MP, n - k)) % md) % md << '\n';
		}
		else {
			cout << "0\n";
		}
	}
	return 0;
}