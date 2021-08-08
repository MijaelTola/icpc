#include <bits/stdc++.h>

using namespace std;

template <typename T, int MAX_N>
struct Hash {
    T p,x,n;    
    vector<T> h,h1,vpow;

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
        int sz = j - i + 1;
        return ((h[i] - mul(h[j + 1], vpow[sz]) % p) + p) % p;
    }

    T getRh(int i, int j) {
        int sz = j - i + 1;
        return ((h1[j] - mul(h1[i - 1], vpow[sz] % p)) + p) % p;
    }
};

unordered_map<int,int> p;
unordered_map<int,int> tot;

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]);}
void merge(int x, int y) { 
    p[find(x)] = find(y); 
    tot[find(x)] += tot[find(y)];
};

map<pair<int,int> ,int> mp;

int main() {

    int n,k;
    string s;
    cin >> n >> k >> s;
    
    vector<int> b;

    for (int i = 0; i < 2 * (int)s.size(); ++i)
        b.push_back(s[i % s.size()] - 'a' + 1);

    Hash<long long, 2000010> h(33, INT_MAX);
    Hash<long long, 2000010> hh(33, 1e9 + 7);

    Hash<long long, 2000010> h2(33, INT_MAX);
    Hash<long long, 2000010> hh2(33, 1e9 + 7);

    h.build(b);
    hh.build(b);
    
    int q;
    cin >> q;

    int val = 1;
    while(q--) {
        string t;
        cin >> t;
        vector<int> bb;

        for (int i = 0; i < (int)t.size(); ++i) {
            bb.push_back(t[i] - 'a' + 1);   
        }
        h2.build(bb);
        hh2.build(bb);
        auto a1 = h2.getH(0, t.size());
        auto a2 = hh2.getH(0, t.size());
        mp[{a1, a2}] = val++;
    }
    
    for (int i = 0; i < k; i++) {
        unordered_map<int,int> res;
        vector<int> ans;
        for (int j = i, cnt = 0; cnt < n; j += k, cnt++) {
            int vh = h.getH(j, j + k - 1);
            int vh2 = hh.getH(j, j + k - 1);
           if(mp[{vh, vh2}]) {
                ans.push_back(mp[{vh, vh2}]);
                res[mp[{vh, vh2}]] = j;
            }
        }
        if((int)res.size() == n) {
            cout << "YES\n";
            for (auto x: ans)
                cout << x << " ";
            cout << "\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}

