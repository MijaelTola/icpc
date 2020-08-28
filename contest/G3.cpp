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

char ans[210][210];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n; 
    while(cin >> n and n){
    string s; cin >> s;
    int pos = 0;
    int h = 0;
    for (int i = 0; i  < (int)s.size(); ++i){
        ans[h][pos] = s[i]; 
        if(pos == n-1){
            pos = 0;
            h++;
        }else pos++;
    }
    
    for (int i = 0 ; i < h; ++i)
        if(i&1) reverse(ans[i],ans[i]+n);

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < h; ++j)cout << ans[j][i];
    }
    cout << "\n";
    }
    return 0;
}

