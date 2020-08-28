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

ll v[100010];
ll a[100010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    while(cin >> n >> m and n != -1 and m != -1){
        for (int i = 0; i < n; ++i){
            cin >> v[i];
            v[i] *= m;
        }
        a[0] = v[0];
        for (int i = 1; i < n; ++i) a[i] = v[i]+a[i-1];
        ll ans = 0;
        for (int i = 0; i < n; ++i) ans += (v[i]+a[i]);
        cout << ans-a[n-1] << "\n";
    }
    return 0;
}

