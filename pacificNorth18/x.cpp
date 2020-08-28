#include <bits/stdc++.h>

using namespace std;

bool ver(int x, int y, int t) {
	int a = 0;
	int b = t;
	while(b - a > 1) {
		int mid = (a + b) / 2;
		if(x * mid + y * (mid - 1) >= t or x * mid + y * mid >= t) b = mid;
		else a = mid;
	}
	return b * x + y * (b - 1) == t or b * x + y * b == t;
}
int main() {
	int n; cin >> n;
	cout << n << ":\n";
	for (int i = 2; i <= n; ++i) {
		if(ver(i, i - 1,n) and i + (i - 1) <= n) 
			cout << i << "," << i - 1 << "\n";
		if(ver(i,i,n) and i + i <= n)
			cout << i << "," << i << "\n";
	}
}
