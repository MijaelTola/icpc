#include <bits/stdc++.h>

using namespace std;

string s;
char c[200010];
stack<int> last;
vector<int>alpha[256];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;
	int q; cin >> q;
	for (int i = 0; s[i];i++) {
		alpha[s[i]].push_back(i);
	}
	int p = 0;
	last.push(-1);
	while(q--) {
		string com;
		char l;
		cin >> com;
		if(com == "push") {
			cin >> l;
			int pos = last.top();
			int a = -1;
			int b = alpha[l].size();
			while(b - a > 1) {
				int mid = (a + b) / 2;
				if(alpha[l][mid] > pos) b = mid;
				else a = mid;
			}
			if(b == alpha[l].size()) {
				 cout << "NO\n";
				last.push(s.size());
				continue;
			}else cout << "YES\n";
			last.push(alpha[l][b]);
		} else {
			last.pop();
			int u = last.top();
			if(u < (int)s.size()) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
