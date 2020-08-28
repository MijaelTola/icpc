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

int m[25][25];
int main(){
    
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < 20; ++j)
            cin >> m[i][j];

    int ans =  0;
    for (int i = 0; i < 20; ++i){
        for (int j = 0; j < 20; ++j){
            int p = 1;
            int l = 1;
            for (int k = j; k < j+4; ++k){
                p *= m[i][k];
                l *= m[k][i];
            }
            ans = max(ans,p);
        }
    }
    for (int i = 0; i < 20; ++i){
        for (int j = 0; j < 20; ++j){
            int p = 1;
            int r = 1;
            for (int n = j; n < j+4; ++n){   
                if(n > 20) break;
                int k = n+i;
                int l = n-i;
                if(k < 20) p *= m[n][k];
                if(l >= 0) r *= m[n][l];
            }
            ans = max(ans,max(p,r));
        }
    }
    int cn;
    for (int i = 0; i < 20; ++i){
        cn = 0;
        for (int j = 19; j >= 0; --j){
            int p = 1;
            int r = 1;
            int q = cn;
            for (int n = j; n > j - 4; --n){
                if(n < 0) break;
                int k = i+q;
                int l = q-i;
                if(k < 20)p *= m[n][k];
                if(l >= 0)r *= m[n][l];
                q++;
            }
            cn++;
            ans = max(ans,max(p,r));
        }
    }
    cout << ans << "\n";
    return 0;
}

