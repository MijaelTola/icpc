#include <iostream>
#include <deque>
using namespace std;

deque<int> v;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	string s;
	while(cin >> s){
		v.clear();
		for (int i = 0; i < 8; ++i){
			v.push_back(s[i]-'0');
		}
		int p;
		cin >> p;
		for (int i = 0; i < p;++i){
			int a = v.back();
			a ^= v.at(4);
			a ^= v.at(2);
			v.pop_back();
			v.push_front(a);
		}
		for (int i = 0; i < 8; ++i)
			cout << v[i];
		cout << "\n";
	}
	return 0;
}
