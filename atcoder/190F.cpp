#include <bits/stdc++.h>

using namespace std;


struct SegmentTree {
    int n;
    vector<long long > st;
    
    SegmentTree() {}
    void build(int _) {
        st.resize(3 * _);
        n = _;
    }
    long long  op(long long a, long long b) {
        return a + b;
    }
    void update(int pos,int value){
        for (st[pos += n]= value; pos > 1; pos>>=1)
            st[pos>>1] = op(st[pos], st[pos ^ 1]);
    }
    // interval[l,r)
    long long query(int l,int r){
        long long ans = 0;
        r++;
        for (l += n,r += n;l < r;l >>= 1,r >>= 1){
            if(l & 1) ans = op(ans, st[l++]);
            if(r & 1) ans = op(ans, st[--r]);
        }
        return ans;
    }
};

int v[300010];
int main() {
    
    int n;
    cin >> n;
    
    SegmentTree st;

    st.build(3 * n);

    for (int i = 0; i < n; ++i) 
        cin >> v[i];

    long long ans = 0;

    for (int i = n - 1; i >= 0; i--) {
        st.update(v[i], 1);
        ans += st.query(0, v[i] - 1);
    }
    

    vector<long long> a;
    a.push_back(ans);
    for (int i = 0; i < n - 1; ++i) {
        ans -= st.query(0, v[i] - 1);
        ans += st.query(v[i] + 1, n);
        a.push_back(ans);
    }

    
    for (auto x: a)
        cout << x << "\n";


    return 0;
}

