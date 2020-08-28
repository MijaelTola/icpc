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

int main(){
    
    int n; 
    int k; cin >> k;
    while(k--){
        cin >> n;
        int x = 0; int x1 = 0;
        for (int i = 0; i < n; ++i){
            int t; cin >> t;
            if(i&1) x += t;
            else x1 += t;
        }
        for (int i = 0; i < n; ++i){
            int t; cin >> t;
            if(i&1) x1 += t;
            else x += t;
        }

        cout << min(x,x1) << "\n";
    }
    return 0;
}

