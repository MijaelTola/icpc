#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>
#include <string> 
#include <sstream>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;

int n;
ll k;
int v[25];

map<pair<int,ll>, bool> dp;

bool f(int pos, ll capacity){
	if(pos == n) return capacity == 0LL;
	
	if(dp.count({pos,capacity})) return dp[{pos,capacity}];
	bool ans = false;
	
	ans |= f(pos+1,capacity%v[pos]);
	ans |= f(pos+1,capacity);
	
	return dp[{pos,capacity}] = ans;
}
int main(){
	cin >> n >> k;
	
	for (int i = 0; i < n; ++i) cin >> v[i];
	sort(v,v+n);
	reverse(v,v+n);	
	if(f(0,k)) cout << "possible\n";
	else cout << "impossible\n";
	
	return 0;
}
