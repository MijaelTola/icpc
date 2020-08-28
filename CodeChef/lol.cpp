#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<int> dx;
set<int> dy;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		for (int i = 0; i < n; ++i){
			int x,y; cin >> x >> y;
			dx.insert(x);
			dy.insert(y);
		}
		if(dx.size() < dy.size()) cout << dx.size() << "\n";
		else cout << dy.size() << "\n";
	}
	return 0;
}
