#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int cases;
	cin >> cases;
		while (cases--) {
			int a;
			cin >> a;int b = a-1;
			int c = 0;
			for (int i = 0; i < 31;i++) {
				if ((a & (1 << i)) != (b & (1 << i)))c++;
				}
				cout << c << "\n";
		}
		return 0;
}


