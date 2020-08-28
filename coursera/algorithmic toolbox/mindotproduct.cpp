#include <iostream>
#include <algorithm>

using namespace std;

long long a[1010],b[1010];
int main(){
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	sort(a,a+n);
	sort(b,b+n);
	reverse(b,b+n);
	long long ans = 0;
	for (int i = 0; i < n; ++i) ans += a[i]*b[i];
	cout << ans << "\n";
	return 0;
}
