#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int v[10000];
	for (int i = 1; i <= n; ++i)
	{
		int x; cin >> x;
		v[i] = x + v[i-1];
	}

	int ans = 1e6;
	for (int i = 1; i < n; ++i)
	{
		int a = v[n] - v[i];
		int b = v[i];
		int dif = abs(a-b);
		ans = min(ans,dif);
		//cout << b << " " << a << endl;
	}
	cout << ans << endl;
	return 0;
}