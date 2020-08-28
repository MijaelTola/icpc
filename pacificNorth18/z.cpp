#include <bits/stdc++.h>
using namespace std;
bool nozero(int u) {
	while(u > 0) {
		int k = u % 10;
		if (!k)return 0;
		u/=10;
	}
	return 1;
}
int main() {
	int n;
	cin >> n;
	for (int i = n + 1; ;i++) {
		if (nozero(i))return cout << i << endl,0;
	}
	return 0;
}
