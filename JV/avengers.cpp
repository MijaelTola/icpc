#include <iostream>
#include <vector>
#include <set>

using namespace std;
set<string> s;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int m;
	while(cin >> m){
		s.clear();
		for (int i = 0; i < m; ++i){
			int n; cin >> n;
			for (int j = 0; j < n; ++j){
				string x; 
				cin >> x;
				s.insert(x);
			}
		}
		string p; cin >> p;
		int ans = 0;
		for (string x: s){
			if(x == p) break;
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
