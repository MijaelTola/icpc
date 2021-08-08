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
        return a ^ b;
    }
    void update(int pos,int value){
        for (st[pos += n] ^= value; pos > 1; pos>>=1)
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
int main() {
    
    int n,q;
    cin >> n >> q;

    SegmentTree st;
    st.build(n);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        st.update(i,x);
    }

    while(q--) {
        int a,b,c;
        cin >> a >> b >> c;

        if(a == 1) {
            b--;
            st.update(b, c);
        } else {
            b--,c--;
            cout << st.query(b,c) << "\n";
        }
    }

    return 0;
}

