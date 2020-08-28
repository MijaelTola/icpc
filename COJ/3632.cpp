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
#include <algorithm>
using namespace std;

typedef long long ll;

int st[500100];
int n;
void update(int pos, int value){
    for (st[pos+= n]|=(1<<value);pos>1;pos>>=1){
        for (int i = 0; i < 11; ++i)
            if(st[pos]&(1<<i) or st[pos^1]&(1<<i))
                st[pos>>1] |= (1<<i);
    }
}
int query(int l, int r){
    int ans = 0;
    r++;
    for (l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1){
            for (int i = 0; i <= 9; ++i)
                if(st[l]&(1<<i)) ans |= (1<<i);
            l++;
        }
        if(r&1){
            r--;
            for (int i = 0; i <= 9; ++i)
                if(st[r]&(1<<i)) ans |= (1<<i);
        }
    }
    return __builtin_popcount(ans);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> n){
        memset(st,0,sizeof st);
        for (int i = 1; i <= n; ++i){
            int x; cin >> x;
            update(i,x);
        }
        int q; cin >> q;
        while(q--){
            int x,y; cin >> x >> y;
            cout << query(x,y) << "\n";
        }
    }
    return 0;
}

