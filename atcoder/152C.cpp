#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    int n;
    int type;
    vector<int> st;
    int NEUTRO;
    void init(int _, int __, int ___) {
        n =  _;
        st.resize(5 * _);
        NEUTRO = ___;
        type = __;
    }
    SegmentTree() {}
    
    int ope(int x, int y) {
        if(type == 0) return max(x,y);
        if(type == 1) return min(x,y);
        if(type == 2) return x + y;
        return 0;
    }

    void update(int pos,int value){
        for (st[pos+=n]= value; pos > 1; pos>>=1) {
            st[pos>>1] = ope(st[pos],st[pos^1]);
        }
    }
    // interval[l,r)
    int query(int l,int r){
        int ans = NEUTRO;
        r++;
        for (l += n,r +=n ; l < r ; l >>= 1,r >>= 1){
            if(l&1) ans = ope(ans,st[l++]);
            if(r&1) ans = ope(ans,st[--r]);
        }
        return ans;
    }
};

int v[200010];

int main() {
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    SegmentTree st;
    st.init(n, 2, 0);
    
    int ans = 0;
    
    for (int i = 0; i < n; ++i) {
        st.update(v[i], 1);
        ans += (st.query(v[i], n) == i + 1);
    }
    cout << ans << "\n";
    return 0;
}

