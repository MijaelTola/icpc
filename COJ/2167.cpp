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

int v[5];
int main(){
    
    int t; cin >> t;
    while(t--){
        memset(v,0,sizeof v);
        int n; cin >> n;
        for (int i = 0; i < n; ++i){
            int x; cin >> x;
            v[x]++;
        }
        int ans = 0;
        ans += v[4];
        ans += v[3];
        v[1] -= v[3];
        if(v[1] < 0) v[1] = 0;
        ans += (v[1]+2*v[2])/4;
        if((v[1]+2*v[2])%4) ans ++;
        cout << ans << endl;
    }
    return 0;
}

