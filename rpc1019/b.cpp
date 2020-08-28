#include <bits/stdc++.h>

using namespace std;

const long long mod = 4300000013LL;
long long fact[300010];
long long cur[300010];

struct segmentTree {
    const int NEUTRO = 0;
    long long st[300010];
    int n;
    segmentTree(int _) {
        n = _;
        memset(st, 0, sizeof st);
    }
    void update(int pos,long long value){
        for (st[pos += n] += value; pos > 1; pos >>= 1)
            st[pos >> 1] = st[pos] + st[pos ^ 1]; 
    }
    // interval[l,r)
    long long query(int l,int r){
        long long ans = NEUTRO;
        r++;
        for (l += n,r += n;l < r;l >>= 1,r >>= 1){
            if(l & 1) ans += st[l++];
            if(r & 1) ans += st[--r];
        }
        return ans;
    }
};

long long multiply(long long a, long long b) {
    long long ans = 0;
    a %= mod;
    while(b > 0) {
        if(b & 1) ans = (ans + a) % mod;
        a = (2 * a) % mod;
        b >>= 1LL;
    }
    return ans % mod;
}

long long modpow(long long x, long long y) {
    long long ans = 1;
    x %= mod;
    while(y) {
        if(y & 1) ans = multiply(ans, x);
        y >>= 1LL;
        x = multiply(x, x) % mod;
    }
    return ans;
}

long long invMod(long long x) {
    return modpow(x, mod - 2);
}

int main() {
    //ios::sync_with_stdio(false); cin.tie(0);
    fact[0] = 1;
    for (int i = 1; i < 100010; ++i) 
        fact[i] = (i * fact[i - 1]) % mod;

    int t;
    cin >> t;
    while(t--) {
        memset(cur, 0, sizeof cur);
        int n,q;
        cin >> n >> q;
        map<long long, int> mp;
        segmentTree st(n);
        set<int> s;
        long long mul = 1;
        while(q--) {
            char c;
            cin >> c;
            if(c == 'U') {
                int pos, val;
                cin >> pos >> val;
                s.insert(pos);
                pos--;
                st.update(pos, val);
                if(cur[pos] != 0) {
                    mul = multiply(mul, invMod(fact[mp[cur[pos]]]));
                    mp[cur[pos]]--;
                }
                cur[pos] += val;
                if(cur[pos] != 0) mul = multiply(mul, invMod(fact[mp[cur[pos]]]));
                mp[cur[pos]]++;
                mul = multiply(mul, fact[mp[cur[pos]]]) % mod;
                continue;
            }

            if(c == 'Q') {
                int l,r;
                cin >> l >> r;
                l--,r--;
                cout << st.query(l,r) << "\n";
                continue;
            }

            if(c == 'W') {
                cout << multiply(fact[s.size()], invMod(mul)) % mod << "\n";
                continue;
            }
        }
    }
    return 0;
}

