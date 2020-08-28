#include <bits/stdc++.h>

using namespace std;

const int NEUTRO = 0;
struct segmentTree {
    const int NEUTRO = 0;
    int n;
    vector<int> st;
    void init(int _) {
        n = _;
        st.resize(5 * n);
    }

    void update(int pos,int value){
        for (st[pos += n]= value; pos > 1; pos>>=1)
            st[pos>>1] = st[pos] + st[pos^1]; 
    }
    // interval[l,r)
    int query(int l,int r){
        int ans = NEUTRO;
        r++;
        for (l += n,r += n;l < r;l>>=1,r>>=1){
            if(l & 1) ans += st[l++];
            if(r & 1) ans += st[--r];
        }
        return ans;
    }
};

segmentTree st[30];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,q;
    string s;
    cin >> n >> s;

    for (int i = 0; i < 30; ++i) st[i].init(n);

    for (int i = 0; i < (int)s.size(); ++i) {
        st[s[i] - 'a'].update(i, 1);
    }
    

    cin >> q;
    while(q--) {
        int c;
        cin >> c;
        if(c == 1) {
            int p;
            char x;
            cin >> p >> x;
            p--;
            char cur = s[p];
            st[cur - 'a'].update(p, 0);
            s[p] = x;
            st[x - 'a'].update(p, 1);
        } else {
            int ans = 0;
            int l, r;
            cin >> l >> r;
            l--,r--;
            for (int i = 0; i < 30; ++i) 
                ans += st[i].query(l, r) != 0;
            cout << ans << "\n";
        }

    }
    return 0;
}

