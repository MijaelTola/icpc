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

int v[600];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    for (int k = 1; k <= t; ++k){
        int n; cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        sort(v,v+n);
        reverse(v,v+n);
        int ans = 0;

        int l = 0; int r = n;
        int kq = 1; 
        while(l < r){
            if(v[l]*kq >= 50){
                ans++;
                l++;
                kq = 1;
            }else{
                r--;
                kq++;
            }
        }
        cout << "Case #"<<k << ": " <<ans << "\n";
    }
    return 0;
}

