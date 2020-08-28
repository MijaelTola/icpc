#include <bits/stdc++.h>
using namespace std;
/*set<pair<int,int> >st;
int x, y, d, n;
void solve(int a, int b) {
	int k = n / a;
	if (k * a > n) {
		k -= a;
	}
	if (k < 0)return;
	n -= k * a;
	k = n / b;
	if (b * k == n) {
		st.emplace(max(a,b), min(a,b));
	}
}
int main() {
	cin >> n;
	d = n;
	for (int i = 2; i < n; i++) {
		solve(i, i - 1);
		solve(i, i);
		solve(i, i + 1);
	}
	cout << st.size() << endl;
	return 0;
}*/

bool ver(int x, int y, int t) {
	int a = 0;
	int b = t;
	
	while(b - a > 1) {
		int mid = (a + b) / 2;
	//	cout << mid << "\n";
		if(x * mid + y * (mid - 1) >= t or x * mid + y * mid >= t) b = mid;
		else a = mid;
	}
	
	//if(b * x + y * (b - 1) == t or b * x + y * b == t)cout <<  x << " " << y << " " << b << " " << t << " curAnsa\n";
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
