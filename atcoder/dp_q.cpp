#include <bits/stdc++.h>

using namespace std;

struct segmentTree {
    const long long NEUTRO = 0;
    long long st[500010];
    int n = 200010;
    
    void update(long long pos, long long value){
        for (st[pos += n] = value; pos > 1; pos >>= 1)
            st[pos >> 1] = max(st[pos],st[pos ^ 1]); 
    }
 
    // interval[l,r)
    long long query(int l,int r){
        long long ans = NEUTRO;
        r++;
        for (l += n, r += n; l < r; l >>= 1,r >>= 1){
            if(l & 1) ans = max(ans, st[l++]);
            if(r & 1) ans = max(st[--r], ans);
        }
        return ans;
    }
};

long long h[200010];
long long a[200010];
segmentTree dp;

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> h[i];

    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    
    for (int i = 0; i < n; ++i) 
        dp.update(h[i], dp.query(0, h[i]) + a[i]);
    

    cout << dp.query(0, 200010) << "\n";

    return 0;
}

