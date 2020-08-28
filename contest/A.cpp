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

string x;

ll dp[2000010];

ll f(int pos){ 
    if(pos == (int)x.size()) return 1;
    if(dp[pos] != -1) return dp[pos];
    if(x[pos] == '0') return 0;   
    ll ans = f(pos+1);
    ll number = 0;
    if(pos != (int)x.size()-1) number = (x[pos]-'0')*10+(x[pos+1]-'0');
    if(number > 9 and number < 27) ans += f(pos+2);
    return dp[pos] = ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> x and x != "0"){
        memset(dp,-1,sizeof dp);
        cout << f(0) << "\n";
    }
    return 0;
}

