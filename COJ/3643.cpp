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

using namespace std;

typedef long long ll;
int v[13601000];
int c[13601000];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    for (int i = 1; i <= 3500; ++i){ v[i] = (i*(i+1))/2;}
    for (int i = 1; i <= 3500; ++i){
        c[v[i]] = 1;
        for (int j = i; j <= 3500; ++j){
            ll sum = v[i]+v[j];
            if(c[sum] != 1) c[sum] = 2;
        }
    }  
    int x; 
    while(cin >> x) {
        if(!c[x]) cout << 3 << "\n";
        else cout << c[x] << "\n";
    }
    return 0;
}

