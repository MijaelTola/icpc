#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	--n;
	if (n == 1)return cout << 1 << "\n",0;
	long long sum = (n * (n + 1)) / 2LL;
	long long tot = (n * (n + 1)) / 2LL;
	tot++;
	tot /= 2;
	long long a = -1, b = n + 1;
	while(b - a > 1) {
		long long mid = (a + b) >> 1LL;
		long long diff = (n - mid);
		long long dd = (diff * (diff + 1)) >> 1LL;
		dd = sum - dd;
		if (dd >= tot)b = mid;
		else a = mid;
	}
	cout << b << "\n";
    return 0;
}
