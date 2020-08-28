#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
priority_queue<ull> q;
int main(){
	int n; cin >> n;
	
	for (int i = 0; i < n; ++i){
		ull x; cin >> x;
		q.push(x);
	}
	ull a = q.top(); q.pop();
	ull b = q.top();
	cout << a*b << endl;
	return 0;
}
