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

using namespace std;

typedef long long ll;

ll invert(ll x){
    vector<ll> v;
    ll ans = 0LL;
    while(x > 0LL){
        v.push_back(x%10LL);
        x/=10LL;
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < (int)v.size(); ++i){
        ans += v[i];
        if(i + 1 < (int)v.size()) ans *= 10LL;
    }
    return ans;
}

int main(){
    ll n; cin >> n;
    int ans = 0;
    while(n > 0){
        ans++;
        ll m = invert(n);
        n -= m;
    }
    cout << ans << endl;
    return 0;
}

