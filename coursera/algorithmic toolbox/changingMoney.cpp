#include <iostream>

using namespace std;

int main(){
	int n; cin >> n;
	int ans = 0;
	ans += n/10;
	n%=10;
	ans += n/5;
	n%=5;
	ans += n;
	cout << ans << "\n";
	return 0;
}
