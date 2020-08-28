#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

vector<ll> v;
set<ll> used;
int main(){
	ll n; cin >> n;
	ll p = 1;
	while(n>0){
		if(!used.count(n-p) and p != n-p) {
			used.insert(p);
			n-=p;
	//		cout <<n << " "  <<p << endl;
		} p++;
	}
	cout << used.size() << "\n";
	for (ll x: used) cout << x << " ";
	cout << "\n";
	return 0;
}
