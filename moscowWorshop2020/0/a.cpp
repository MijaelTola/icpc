#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    vector<long long> st;
    SegmentTree() {}
    int n;

    void init(int _) {
        st.resize(3 * _, 0);
        n = _;
    }
    void update(int pos, long long value){
        for (st[pos+=n] += value; pos > 1; pos>>=1)
            st[pos>>1] = st[pos] + st[pos^1]; 
    }

    long long query(int l,int r){
        long long ans = 0;
        r++;
        for (l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) ans += st[l++];
            if(r&1) ans += st[--r];
        }
        return ans;
    }
};

int main() {

    int s;
    cin >> s;

    vector<pair<int, pair<int,int> > > a(s);

    for (int i = 0; i < s; ++i) {
        cin >> a[i].first >> a[i].second.first;
        a[i].second.second = i + 1;
    }
    
    int c;
    cin >> c;

    multiset<pair<int,int> > b;
    
    for (int i = 0; i < c; ++i) {
        int x,y;
        cin >> x >> y;
        b.insert({x,y});
    }

    
    SegmentTree st;

    st.init(200010);
    
    long long ans = 0;

    for (int i = 0; i < s; ++i) {

        while((*b.begin()).first <= a[i].first and !b.empty()) {
            auto x = b.begin();
            st.update((*x).second,1);
            b.erase(x);
        }


        long long cnt = max(0ll,st.query(a[i].second.first, 200000));
        st.update(199999, -cnt);
        ans += a[i].second.second * cnt;
    }

    cout << ans << "\n";
    

    return 0;
}

