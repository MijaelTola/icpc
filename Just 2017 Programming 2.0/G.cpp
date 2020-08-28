#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	while(cin >> n >> m) {
		if(m % n == 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}