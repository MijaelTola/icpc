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

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int x;
        int last = 0;
        ll ans = 0;
         cin >> last;
        while(cin >> x and x){
            if(last*2 < x){
                ll dif = x-last*2;
                ans += dif;
            }
            last = x;
        }
        cout << ans << "\n";
    }
    return 0;
}

