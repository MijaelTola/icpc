#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n){
		int total = 0;
		for (int i = 0; i < n; ++i){
			int x; cin >> x;
			total += x;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i){
			int x; cin >> x;
			if(total > 0){
				total -= x;
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
