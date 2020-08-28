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

bool ver[10];
ll dp[1000][2][2];
string convert(ll x, ll base){
    string ans = "";
    while(x > 0){
        ans = (char)(x%base+'0') + ans;
        x/=base;
    }
    if(ans == "")return "";
    return ans;
}
string lim;
int sz;
char p;
ll d,h,b;
ll f(int pos, bool flag, bool first){
    if(pos == sz) return 1LL;
    ll ans = 0;
    if(dp[pos][flag][first] != -1) return dp[pos][flag][first];
    if(!flag){
        for (int i = 0; i < b; ++i){
            if(ver[i])ans += f(pos+1,false,false);
            else if(i == 0 and first) ans += f(pos+1,false,true);
        }
    }else{
        for (int i = 0; i < lim[pos]-'0'; ++i){
            if(ver[i])ans += f(pos+1,false,false);
            else if(i == 0 and first) ans += f(pos+1,false,true);
        }
        if(ver[lim[pos]-'0'])ans += f(pos+1,true,false);
        else if(lim[pos]-'0' == '0' and first) ans += f(pos+1,false,true);
    }
    return dp[pos][flag][first] = ans;
}

/*
THE TRIVIAL ONE GAMAX
*/
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    string l;
    while(cin >> d >> h >> b >> l and d != -1 and h != -1 and b != -1 and l != "*"){
        memset(ver,false,sizeof ver);
        memset(dp,-1,sizeof dp);
        for (int i = 0; i < (int)l.size(); ++i)
            if(l[i] == 'S') ver[i] = true;
        lim = convert(h,b);
        sz = lim.size();
        ll ans = f(0,true,true);
        memset(dp,-1,sizeof dp);
        lim = convert(d-1,b);
        sz = lim.size();
        ll ans2 = f(0,true,true);
        if(d == 0 and l[0] == 'S') ans2--;
        cout << ans -  ans2 << "\n";
    }
    return 0;
}

