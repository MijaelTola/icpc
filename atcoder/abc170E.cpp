#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {

    int n;
    vector<int> st;
    
    SegmentTree() {}
    void build(int _) {
        st.resize(4 * _, INT_MAX);
        n = _;
    }

    int op(int a, int b) {
        return min(a,b);
    }
    void update(int pos,int value){
        for (st[pos += n]= value; pos > 1; pos>>=1)
            st[pos>>1] = op(st[pos], st[pos ^ 1]);
    }
    // interval[l,r)
    int query(int l,int r){
        int ans = INT_MAX;
        r++;
        for (l += n,r += n;l < r;l >>= 1,r >>= 1){
            if(l & 1) ans = op(ans, st[l++]);
            if(r & 1) ans = op(ans, st[--r]);
        }
        return ans;
    }
};

set<pair<int,int> > s[2000010];
int pos[2000010];
int val[2000010];

int main() {

    ios::sync_with_stdio(false); cin.tie(0);
    SegmentTree st;

    st.build(200010);
    
    int n,m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        int x,y;
        cin >> x >> y;
        s[y].insert({x, i});
        pos[i] = y;
        val[i] = x;
    }

    for (int i = 1; i < 200010; ++i) {
        if(s[i].size() == 0) continue;
        st.update(i, (*s[i].rbegin()).first);
    }

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;

        int p = pos[x];
        int v = val[x];

        s[p].erase({v, x});
        s[y].insert({v, x});
        pos[x] = y;
        if(s[p].size()) st.update(p, (*s[p].rbegin()).first);
        else  st.update(p, INT_MAX);
        if(s[y].size()) st.update(y, (*s[y].rbegin()).first);
        else st.update(p, INT_MAX);

        cout << st.query(0, 200000) << "\n";

    }
    return 0;
}

