#include <bits/stdc++.h>

using namespace std;

const long long md = 1e9 + 7;
const int N = 1e4 + 10;

string str;
int n;
long long dp[N][1028];

long long f(int idx, int msk) {
	if (idx == n) {
		return 1;
	}

	if (dp[idx][msk] != -1) return dp[idx][msk];

	int dig = str[idx] - '0';
	long long res = f(idx + 1, (1 << dig));
	if (msk != 0 && ((1 << dig) & msk) == 0) {
		res += f(idx + 1, msk | (1 << dig));
	}
	return dp[idx][msk] = res % md;
}


int main() {
	while (cin >> n) {
		cin >> str;
		memset(dp, -1, sizeof dp);
		cout << f(0, 0) << '\n';
	}
	return 0;
}