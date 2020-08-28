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
typedef pair<int,pair<int,int> > ii;
const int maxn = 200010;
struct triple{
    int val;
    int pos;
    int vuelta;
    triple(){}
    bool operator()(const triple &t){
        return val < t.val;
    }
};
int ba[maxn];
int ida[maxn];
int st[2*maxn],n;
int aux[maxn];
int a[maxn];
triple tri[maxn];
void clean(){
    for(int i = 0; i < 2*maxn; ++i){
        st[i] = 0;    
    }
}
void update(int pos, int value){
    for (st[pos += n] = value; pos > 1; pos >>=1)
        st[pos>>1] = max(st[pos],st[pos^1]);
}
//[l,r)
int query(int l, int r){
    int ans = 0;
    r++;
    for (l+=n,r+=n;l<r; l>>=1,r>>=1){
        if(l&1)ans = max(ans,st[l++]);
        if(r&1)ans = max(ans,st[--r]);
    }
    return ans;
}

bool cmp(const triple &A, const triple &B){
    if(A.val == B.val) return A.pos < B.pos;
    return A.val < B.val;
}

int bs(int x){
    int a = 0; int b = n;
    while(b-a>1){
        int mid = (a+b)>>1;
        if(ba[mid] > x) b = mid;
        else a = mid;
    }
    return b;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--){
        clean();
        cin >> n;
        for (int i = 0;i < n; ++i){
            cin >> tri[i].val;
            tri[i].pos = i;
            a[i] = tri[i].val;
        }
        
        ida[0] = 1;
        for (int i = 1;i < n; ++i){
            if(tri[i].val > tri[i-1].val) ida[i] = ida[i-1]+1;
            else ida[i] =1;
        }
        tri[n-1].vuelta = 1;
        for (int i = n-2; i >= 0; --i){
            if(tri[i].val < tri[i+1].val) tri[i].vuelta = tri[i+1].vuelta+1;
            else tri[i].vuelta = 1;
        }
        sort(tri,tri+n,cmp);
        for (int i = 0; i < n; ++i) ba[i] = tri[i].val;
        
        for (int i = 0; i < n; ++i){
            update(i,tri[i].vuelta);
            aux[tri[i].vuelta] = i;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i){
            int pos = upper_bound(ba,ba+n,a[i]) - ba;
            int q = query(pos,n);
            ans = max(ans,q+ida[i]);
            update(aux[i],0);
        }
        cout << ans << "\n";
    }

    return 0;
}

