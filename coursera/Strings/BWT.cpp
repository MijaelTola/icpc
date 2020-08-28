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

using namespace std;

typedef long long ll;

vector<string> v;
int main(){
    string x;
    
	while(cin >> x){
		v.clear();
		for (int init = 0; init < (int)x.size(); ++init){
			string p = "";
			for (int i = init; i < (int)x.size(); ++i)
				p += x[i];
			string t = "";
			for (int i = 0; i < init; ++i) t += x[i];
			v.push_back(p+t);
		}
		sort(v.begin(),v.end());
		string ans = "";
		for (int i = 0; i < (int)v.size(); ++i) ans +=  v[i][v.size()-1];
		cout << ans << endl;
	}
	return 0;
}

