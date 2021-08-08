#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9 + 7;
 
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
 
 
int main() {
    
    int n,m;
    string s;
    cin >> n >> m >> s;
 
    vector<int> v(m);
 
    for (int &x: v) {
        cin >> x;
        x--;
    }
    v.push_back(n);
 
    vector<int> b;
 
    for (auto c: s)
        b.push_back(c - 'a' + 1);
 
 
    Hash<long long, 1000010> h(33, INT_MAX);
    h.build(b);
 
    int sz = s.size();
    int cnt = v[0];
 
    for (int i = 1; i < (int)v.size(); ++i) {
        int last = v[i - 1];
        int lastR = last + sz - 1;
        int cur = v[i];
 
        if(cur + sz - 1 > n and i + 1 < (int)v.size()) return cout << "0\n", 0;
        if(lastR >= cur) {
            int tm = lastR - cur;
            if(h.getH(sz - tm - 1, sz - 1) != h.getH(0, tm))
                return cout << "0\n", 0;
        } else {
            cnt += cur - lastR - 1;
        }
    }
 
    long long ans = 1;
 
    for (int i = 0; i < cnt; ++i) {
        ans *= 26;
        ans %= mod;
    }
    cout << ans << "\n";
    return 0;
}

