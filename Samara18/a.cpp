#include <bits/stdc++.h>

using namespace std;

int main() {
	int s,g;
	cin >> s >> g;
	if(__gcd(s,g) != g or s - g == 0) return cout << "-1\n",0;
	cout << g << " " << abs(s - g) << "\n";
	return 0;
}
