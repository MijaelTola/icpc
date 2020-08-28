#include <bits/stdc++.h>

using namespace std;

int in () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

int t,n,m;
vector<int> mx[100010];
vector<int> mxc[100010];

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

    Hash<long long, 100010> hash(1299709, INT_MAX);

    t = in();
    while(t--) {
        n = in();
        m = in();

        int v[n][m];

        for (int i = 0; i < n; ++i)
            mx[i].clear();
        for (int i = 0; i < m; ++i)
            mxc[i].clear();

        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j) 
                v[i][j] = in();
        
        for (int l = 0; l < n; ++l) {
            vector<int> r;

            for (int j = 0; j < m; ++j) 
                r.push_back(v[l][j]);

            hash.build(r);

            for (int i = 0; i < (int)r.size(); ++i) {
                int a = 0, b = min(i, (int)r.size() - i) + 1;
                while(b - a > 1) {
                    int mid = (a + b) / 2;
                    int h1 = hash.getH(i - mid, i - 1);
                    int h2 = hash.getRh(i + 1, i + mid);
                    if(h1 == h2) a = mid;
                    else b = mid;
                }
                mx[l].push_back(a);
            }

        }

        for (int l = 0; l < m; ++l) {
            vector<int> c;
            for (int j = 0; j < n; ++j) 
                c.push_back(v[j][l]);

            hash.build(c);

            for (int i = 0; i < (int)c.size(); ++i) {
                int a = 0, b = min(i, (int)c.size() - i) + 1;
                while(b - a > 1) {
                    int mid = (a + b) / 2;
                    int h1 = hash.getH(i - mid, i - 1);
                    int h2 = hash.getRh(i + 1, i + mid);
                    if(h1 == h2) a = mid;
                    else b = mid;
                }
                mxc[l].push_back(a);
            }

        }
    
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans += min(mx[i][j], mxc[j][i]) + 1;
            }
        }
        
        printf("%lld\n", ans);


    }
    return 0;
}

