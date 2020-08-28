#include <bits/stdc++.h>
using namespace std;

bool solve(const string &s){
	string ss = s;
	reverse(ss.begin(), ss.end());
	if (ss == s) {
		return ss.size() %2;
	}
	return true;
}
int main() {
	string s;
	cin >> s;
	bool check = true;
	for (int i = 0; i < s.size();i++) {
		string k = "";
		for (int j = i; j < s.size();j++) {
			k+= s[j];
			check &= solve(k);
		}
		if (!check)break;
	}
	if(check) cout << "Odd.\n";
	else cout << "Or not.";
}
