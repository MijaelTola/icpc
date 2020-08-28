#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    vector<int> st;
    int n;
    SegmentTree(){};
    
    void build(int _) {
        n = _;
        st.resize(3 * n);
    }

    int ope(int a, int b) {
        return a ^ b;
    }

    void update(int pos,int value){
        for (st[pos+=n]= value; pos > 1; pos>>=1)
            st[pos>>1] = ope(st[pos], st[pos^1]);
    }

    int query(int l,int r){
        int ans = 0;
        r++;
        for (l += n,r += n; l < r; l >>= 1, r >>= 1){
            if(l&1) ans = ope(ans, st[l++]);
            if(r&1) ans = ope(ans, st[--r]);
        }
        return ans;
    }
};

int n;
int v[1000010];
int ans[1000010];
map<int,int> last;

int main() {
    
    SegmentTree st1,st2;
    scanf("%d", &n);
    
    st1.build(n);
    st2.build(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", v + i);
        st1.update(i, v[i]);
    }

    int q;
    scanf("%d", &q);
    
    vector<pair<pair<int,int> ,int> > b;
    for (int i = 0; i < q; ++i) {
        int l,r;
        scanf("%d %d", &l, &r);
        l--,r--;
        b.push_back({{r,l}, i});
    }

    sort(b.begin(), b.end());
    
    int p = 0;

    for (int i = 0; i < n; ++i) {
        if(!last.count(v[i])) {
            st2.update(i, v[i]);
        } else {
            st2.update(last[v[i]], 0);
            st2.update(i, v[i]);
        }
        last[v[i]] = i;
        
        while(b[p].first.first <= i and p < q) {
            int l = b[p].first.second;
            int r = b[p].first.first;
            int id = b[p].second;
            int x = st1.query(l,r);
            int y = st2.query(l,r);
            ans[id] = x ^ y;
            p++;
        }
    }

    for (int i = 0; i < q; ++i)
        printf("%d\n", ans[i]);

    return 0;
}

