#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int in[1000100];
int out[1000100];
set<int> s;
set<int> t;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	int k = 0;
	while(cin >> n and n){
		s.clear();
		t.clear();
		for (int i = 0; i < n; ++i) cin >>in[i];
		for (int i = 0; i < n; ++i){
			int x; cin >> x;
			out[x] = i;
		}
		for (int i = 0; i < n; ++i){
			int x = out[in[i]];
			set<int>::iterator a = s.lower_bound(-x);
			set<int>::iterator b = t.lower_bound(x);
			if(a != s.end()) s.erase(a);	
			s.insert(-x);
			if(b != t.end()) t.erase(b);
			t.insert(x);
		}
		cout <<s.size() << " " << t.size() << "\n";
	}
	
	return 0;
}
