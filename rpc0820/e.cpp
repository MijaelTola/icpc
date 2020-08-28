#include <bits/stdc++.h>

using namespace std;

template <typename T, int MAX_N>

struct Hash {

    T p,x,n;    
    vector<T> h,h1,vpow;
    
    Hash() {}

    Hash(T dx, T dp) {
        h.resize(MAX_N);
        h1.resize(MAX_N);
        vpow.resize(MAX_N);

        x = dx, p = dp;
        vpow[0] = 1;
        for (int i = 1; i < MAX_N; ++i)
            vpow[i] = ((T) mul(vpow[i - 1], (T) x)) % p;
    }

    void build(const vector<int> &v) {
        T hash = 0;
        n = v.size();
        for (int i = 0; i < n + 10; ++i) {
            h[i] = h1[i] = 0;
        }

        for (int i = n - 1; i >= 0; i--) {
            hash = ((((T) mul(hash, x) + v[i]) % p) + p) % p;
            h[i] = hash % p;
        }
        hash = 0;
        for (int i = 0; i < n; ++i) {
            hash = ((((T) mul(hash, x) + v[i]) % p) + p) % p;
            h1[i] = hash % p;
        }
    }

    T mul(T a, T b) {
        return (a * b)%p;
        T ans = 0;
        a %= p;
        while(b> 0) {
            if(b & 1) ans = (ans + a) % p;
            a = (2 * a) % p;
            b >>= 1;
        }
        return ans % p;
    }

    T getH(int i, int j) {
        if(j < i) return 0;
        int sz = j - i + 1;
        return ((h[i] - mul(h[j + 1], vpow[sz]) % p) + p) % p;
    }

    T getRh(int i, int j) {
        if(j < i) return 0;
        int sz = j - i + 1;
        return ((h1[j] - mul(h1[i - 1], vpow[sz] % p)) + p) % p;
    }
};

int n,q,l;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    Hash<long long, 100020> h(33, INT_MAX);
    while(cin >> n >> q >> l) {
        map<pair<long long, long long>, int > mp;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            vector<int> b;
            for (char x: s) 
                b.push_back(x - 'a' + 1);
            h.build(b);

            for (int i = 0; i < (int)b.size(); ++i) {
                long long left = h.getH(0,i - 1);
                long long right = h.getH(i + 1, (int)b.size());
                mp[make_pair(left, right)]++;
            }
        }

        while(q--) {
            string s;
            cin >> s;
            vector<int> b;

            for (char x: s) 
                b.push_back(x - 'a' + 1);
            h.build(b);

            long long ans = 0;

            for (int i = 0; i < (int)b.size(); ++i) {
                long long left = h.getH(0, i - 1);
                long long right = h.getH(i + 1, (int)b.size());
                ans += mp[make_pair(left, right)];
            }

            cout << ans << "\n";

        }
    }
    return 0;
}

