#include <iostream>
#include <set>

using namespace std;

int places[100010];
int pos[100010];
set<int> s;
int n,m,q;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i){
		int x;cin >> x;
		pos[i] = x;
		places[x]++;
		s.insert(x);
	}
	for (int i = 0; i < q; ++i){
		int x,y; cin >> x >> y;
		places[pos[x]]--;
		if(places[pos[x]] == 0) s.erase(pos[x]);
		pos[x] = y;
		s.insert(y);
		cout << m - s.size() << "\n";
	}
	
	return 0;
}
