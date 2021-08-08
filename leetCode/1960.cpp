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
        T val = h[i];
        if(j + 1 < n) {
            val -= mul(h[j + 1], vpow[sz]);
        }
        return (val + p) % p;
    }

    T getRh(int i, int j) {
        int sz = j - i + 1;
        T val = h1[j];
        if(i) {
            val -= mul(h1[i - 1], vpow[sz]);
        }
        return (val + p) % p;
    }
};

Hash<long long, 100010> h(33, INT_MAX);
int Left[100010];
int Right[100010];

class Solution {
public:
    long long maxProduct(string s) {
        int n = s.size();
        vector<int> bb, lps(n + 1, 0);
        for (auto c: s)
            bb.push_back(c - 'a' + 1);
        h.build(bb);
        
        auto check = [&] (int id, int k, int n) {
            int l = max(0, id - k);
            int r = min(id + k, n - 1);
            //cout << h.getH(l, id) << " " <<  h.getRh(id, r) << " hash\n";
            return h.getH(l, id) == h.getRh(id, r);
        };
        
        for (int i = 0; i < n; ++i) {
            Left[i] = Right[i] = 0;
            int a = 0, b = (n + 1) / 2;
            while(b - a > 1) {
                int mid = (a + b) / 2;
                if(!check(i, mid, n)) b = mid;
                else a = mid;
            }
            lps[i] = a + 1;
        }
        
        for (int i = 0; i < n; ++i)
            cout << lps[i] << " ";
        cout << "\n";

        for (int i = 0; i < n; ++i) {
            Left[i + lps[i] - 1] = max(Left[i + lps[i] - 1], 2 * lps[i] - 1);
            Right[i - lps[i] + 1] = max(Right[i - lps[i] + 1], 2 * lps[i] - 1);
        }

        for (int i = 1; i < n; ++i) 
            Right[i] = max(Right[i], Right[i - 1] - 2);
        
        for (int i = n - 2; i > 0; i--)
            Left[i] = max(Left[i], Left[i + 1] - 2);

        for (int i = 1; i < n; ++i)
            Left[i] = max(Left[i], Left[i - 1]);

        for (int i = n - 2; i > 0; i--)
            Right[i] = max(Right[i], Right[i + 1]);
        
        long long ans = 0;

        for (int i = 0; i < n - 1; ++i) {
            ans = max(ans, 1LL * Left[i] * Right[i + 1]);
        }
        return ans;
    }
};


int main() {

    Solution s;
    cout << s.maxProduct("ggbswiymmlevedhkbdhntnhdbkhdevelmmyiwsbgg") << "\n";

    return 0;
}

