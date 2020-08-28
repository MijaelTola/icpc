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

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string x; cin >> x;
        int ans = 0;
        for (int i = 0; i < (int)x.size(); ++i){
            if(i+k > (int)x.size()) break;
            int a = 1;
            for (int j = i; j < i+k; ++j)
                a *= (int)(x[j]-'0');
            ans = max(ans,a);
        }
        cout << ans << "\n";
    }
    return 0;
}

