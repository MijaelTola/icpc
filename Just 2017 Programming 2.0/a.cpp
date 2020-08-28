#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;
const int N = 1e5 + 10;

long long fact[N], invfact[N];

long long power(long long a, long long b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = (ans * a) % md;
		b >>= 1;
		a = (a * a) % md;
	}
	return ans;
}

long long inv(long long a) {
	return power(a, md - 2);
}

int main() {
	int n, m, k;
	double p;
	fact[0] = invfact[0] = 1;
	for (int i = 1; i < n; i++) {
		fact[i] = (fact[i - 1] * i) % md; 
		invfact[i] = inv(fact[i]);
	}
	while (cin >> n >> m >> k >> p) {
		int z = (int)(p * 1000.0);
		int deb = inv(1000);
		int P = (z * deb) % md;
		int MP = (1 - P + md) % md;
		cout << ((fact[n - 1] * invfact[k - 1]) % md * (power(P, k) * power(MP, n - k)) % md) % md << '\n';
	}
	return 0;
}