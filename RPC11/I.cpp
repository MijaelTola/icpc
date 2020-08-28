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

int v[50100];
int h[50100];
int h1[50100];
int main(){
    
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> v[i];

    h[0] = 1;

    for (int i = 1; i < n; ++i){
        if(v[i] >= h[i-1]+1) h[i] = h[i-1]+1;
        else h[i] = v[i];
    }
    int ans = 0;
    for (int i = n-1; i >= 0; --i){
        if(v[i] >= h1[i+1]+1) h1[i] = h1[i+1]+1;
        else h1[i] = v[i];
        if(h1[i] == h[i] or h1[i] == h[i-1])
            ans = max(ans,h1[i]);
    }
    cout << ans << "\n";
    return 0;
}

