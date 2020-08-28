#include <iostream>
#include <set>
using namespace std;

set<char> s;
int main(){
	s.insert('a');
	s.insert('g');
	s.insert('d');
	s.insert('f');
	s.insert('s');
	int n;cin >>n;
	int ans = 0;
	for (int i = 0; i < n; ++i){
		string x; cin >> x;
		char last = '1';
		int c = 0;
		for (int i = 0; i < x.size(); ++i){
			if(x[i] == last) c++;
			else{
				c = 1;
				last = x[i];
				if(!s.count(x[i])){
					ans++; break;
				}
			}
			if(c >= 3){
				ans++; break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
