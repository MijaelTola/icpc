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
        while(b) {
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

    string s;
    cin >> s;

    vector<int> b;
    
    b.push_back('z');
    for (char c: s)
        b.push_back(c - 'a' + 1);

    Hash<long long, 2000100> h(33, INT_MAX);
    Hash<long long, 2000100>  h1(33, 1e9+7);
    
    h.build(b);
    h1.build(b);

    int ans = 0;

    for (int i = 1; i < (int)b.size(); ++i) {
        //cout << h.getH(1,i) << " " << h.getRh(1,i) << "\n";
        if(h.getH(1,i) == h.getRh(1,i) and h1.getH(1,i) == h1.getRh(1,i))
            ans = i;
    }
    cout << ans<< "\n";

    return 0;
}

