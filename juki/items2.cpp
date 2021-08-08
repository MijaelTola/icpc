#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define REP(i,n) for(Long i = 0; i < (Long)n; i++)
#define pb push_back
using namespace std;

typedef long long Long;

map<string, set<string>> dir;
map<string, set<string>> rev;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Long n;
	cin >> n;
	cin.ignore();
	REP(i , n) {
		string s;
		getline(cin, s);
	}
	
	Long m;
	cin >> m;
	
	REP(k , m) {
		Long P;
		cin >> P;
		cin.ignore();
		string s;
		getline(cin , s);
		REP(i, P) {
			string item;
			getline(cin, item);
			dir[s].insert(item);
			rev[item].insert(s);
		}
	}
	Long Q;
	cin >> Q;
	REP(q , Q) {
		if (q != 0) {
			cout << "\n";
		}
		Long type;
		cin >> type;
		cin.ignore();
		string s;
		getline(cin, s);
		if (type == 1) {
			if (rev[s].empty()) {
				cout << "None\n";
			} else {
				for (string x : rev[s]) cout << x<< "\n";
			}
		} else {
			if (dir[s].empty()) {
				cout << "None\n";
			} else {
				for (string x : dir[s]) cout << x<< "\n";
			}
		}
		
	}
	
	return 0;
}
