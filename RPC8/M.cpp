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
    int q; cin >> q;
    bool zack,mack;
    while(q--){
        zack = mack = false;
        for (int i = 0; i < 10;  ++i){
           int x; cin >> x;
           cout << x;
           if(i+1<10) cout << " ";
           if(x == 18) mack = true;
           if(x == 17) zack = true;
        }
        cout << "\n";
        if(mack and zack) cout << "both";
        if(mack and !zack) cout << "mack";
        if(!mack and zack) cout << "zack";
        if(!mack and !zack) cout << "none";
        if(q)cout << "\n";
    }
    return 0;
}

