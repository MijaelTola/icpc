#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    int n;
    vector<int> st;
    
    SegmentTree() {}
    void build(int _) {
        st.resize(3 * _);
        n = _;
    }
    int op(int a, int b) {
        return a + b;
    }
    void update(int pos,int value){
        for (st[pos += n] = value; pos > 1; pos>>=1)
            st[pos>>1] = op(st[pos], st[pos ^ 1]);
    }
    // interval[l,r)
    int query(int l,int r){
        int ans = 0;
        r++;
        for (l += n,r += n;l < r;l >>= 1,r >>= 1){
            if(l & 1) ans = op(ans, st[l++]);
            if(r & 1) ans = op(ans, st[--r]);
        }
        return ans;
    }
};

int aa[200010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    SegmentTree da,db;

    int n,k,a,b,q;
    cin >> n >> k >> a >> b >> q;
    
    da.build(n + 10);
    db.build(n + 10);

    while(q--) {
        int x;
        cin >> x;

        if(x == 1) {
            int y,z;
            cin >> y >> z;
            aa[y] += z;
            db.update(y, min(b, aa[y]));
            da.update(y, min(a, aa[y]));
        } else {
            int l;
            cin >> l;
            int r = l + k;
            cout << db.query(0,l - 1) + da.query(r, n + 1) << "\n";
        }

      
    }

    return 0;
}

