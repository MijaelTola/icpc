#include <bits/stdc++.h>
using namespace std;

long long v[1010];
int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	
	int t; cin >> t;
	
	while(t--) {
		memset(v, 0, sizeof v);
		long long x;
		long long n;
		cin >> x >> n;
		if (n == 1) {
			cout << x << "\n";
			continue;
		}
		for (int i = 0; i < min(x, n);i++)v[i]++;
	//	cout << "RESTA " << x << " " << n << " " << (x - n) << endl;
		x -= n;
		int turn, ini, dir;
		if (x <= 0)goto print;
		turn = 0;
		while (x >= n - 1) {
		//	cout << x << " " << (n - 1) << endl;
			long long div = (x / (n - 1));
			x -= (div * (n - 1));
			//div *= (n - 1);
			long long a = div / 2, b = div / 2 + (div % 2);
			//cout <<div << " " << x << " " << a << " " << b << endl;
			if (!turn) {
				for (int i = n - 2; i >= 0; i--)v[i] += b;
				for (int i = 1; i < n;i++)v[i] += a;
			} else {
				for (int i = 1; i < n;i++)v[i] += b;
				for (int i = n - 2; i >= 0; i--)v[i] += a;;
			}
			if (div % 2)
			turn = !turn;
		}
		ini = (!turn ? n - 2 : 1), dir = (!turn ? -1 : 1);
		while (x > 0 && x--) {
			v[ini]++;
			ini += dir;
		}
		print:
		for (int i = 0; i < n;i++){
			if (i)cout <<  " ";
			cout << v[i];
		}
		cout << "\n";
	}
	return 0;
}
