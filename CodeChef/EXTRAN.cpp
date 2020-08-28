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

int v[100010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        sort(v,v+n);
        int ans = -1;
        for (int i = 0; i < n; ++i){
            bool flag = false;
            //cout << v[i-1] << " " << v[i] << " " << v[i+1] << "\n";
            if(i < n-1 and v[i]+1 == v[i+1]) flag |= true;
            if(i > 0 and v[i-1]+1 == v[i]) flag |= true;
            if(i > 0 and v[i-1] == v[i]){
                ans = v[i];
                break;
            }
            if(i < n-1 and v[i] == v[i+1]){
                ans = v[i];
                break;
            }
            if(!flag){
                ans = v[i];
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

