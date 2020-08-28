#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;
typedef unsigned long long ull;
int main(){
	int n;
	while(cin >> n){
		priority_queue<ull> q;
		for (int i = 0; i < n; ++i){
			ull x; cin >> x;
			q.push(-x);
		}
		ull ans = 1;
		while(q.size() >= 2){
			ull x = -q.top(); q.pop();
			ull y = -q.top(); q.pop();
			ull m = x*y;
			ans *= m;
			q.push(-m);
		}
			ans *= -q.top();
			cout << ans << endl;
		}
	return 0;
}
