#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	string a, b;
	cin >> a >> b;
	int l = -1;
	for (int i = 0; i < a.size();i++) {
		if (a[i] != b[i]){l = i;break;}
	}
	int r = -1;
	for (int i = a.size() - 1; i>=0;i--){
		if (a[i] != b[i]) {r = i;break;}
	}
	if (r == -1)return cout << "YES\n", 0;
	reverse(b.begin() + l, b.begin() + r + 1);
	if (a == b) {
		return cout << "YES\n", 0;
	}
	return cout << "NO\n", 0;
	return 0;
}
