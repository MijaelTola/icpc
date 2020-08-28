#include <bits/stdc++.h>

using namespace std;

template <typename T, int MAX_N>
struct Hash {
    T p,x,n;    
    vector<T> h,h1,vpow;
    Hash(const vector<int> &v, T dx, T dp) {
        h.resize(MAX_N);
        h1.resize(MAX_N);
        vpow.resize(MAX_N);
        n = v.size();
        x = dx, p = dp;
        vpow[0] = 1;
        for (int i = 1; i <= n; ++i)
            vpow[i] = ((T) mul(vpow[i - 1], (T) x)) % p;

        T hash = 0;
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

int n;
int main() {
    string s;
    cin >> n >> s;
    vector<int> v;
    for (int i = 0; i < n; ++i) 
        v.push_back((s[i] - 'a') + 1);
    Hash<long long, 100010> h1(v, 33, INT_MAX);
    Hash<long long, 100010> h2(v, 33, 1e9+7);
    
    int a = 0, b = n + 1;
    while(b - a > 1) {
        int mid = (a + b) / 2;
        map<pair<long long, long long>, vector<int> > mp;
        int k = mid;
        for (int i = 0; i < n - k + 1; ++i) 
            mp[make_pair(h1.getH(i, i + k - 1), h2.getH(i, i + k - 1))].push_back(i);

        bool flag = 0;
        for (int i = 0; i < n - k + 1; ++i) {
            pair<long long, long long> cur = make_pair(h1.getH(i, i + k - 1), h2.getH(i, i + k - 1));
            int left = 0;
            if(i - k >= 0) lower_bound(mp[cur].begin(), mp[cur].end(), i - k) - mp[cur].begin();
            int right = lower_bound(mp[cur].begin(), mp[cur].end(), i + k) - mp[cur].begin();
            long long total = left + (mp[cur].size() - right);
            if(total + 1 >= 2) {
                flag = 1;
                break;
            }
        }
        if(flag) a = mid;
        else b = mid;
        
    }
    cout << a << "\n";
    return 0;
}

