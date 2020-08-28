#include <bits/stdc++.h>

using namespace std;

struct Hash {
    long long p,x,n;
    long long h[200000];
    long long h1[200000];
    long long vpow[200000];

    Hash(const vector<int> &v, long long dx, long long dp) {
        memset(h,0,sizeof h);
        memset(h1,0,sizeof h1);
        n = v.size();
        x = dx, p = dp;
        vpow[0] = 1;
        for (int i = 1; i <= n; ++i)
            vpow[i] = ((long long) mul(vpow[i - 1], (long long) x)) % p;
        
        long long hash = 0;
        for (int i = n - 1; i >= 0; i--) {
            hash = ((((long long) mul(hash, x) + v[i]) % p) + p) % p;
            h[i] = hash % p;
        }
        hash = 0;
        for (int i = 0; i < n; ++i) {
            hash = ((((long long) mul(hash, x) + v[i]) % p) + p) % p;
            h1[i] = hash % p;
        }
    }
    long long mul(long long a, long long b) {
        long long  result = 0;
        a %= p;
        b %= p;
        while(b) {
            if(b & 0x1) {
                result += a;
                result %= p;
            }
            b >>= 1;
            if(a < p - a) {
                a <<= 1;
            } else {
                a -= (p - a);
            }
        }
        return result;
    }
    long long getH(int i, int j) {
        int sz = j - i + 1;
        return ((h[i] - mul(h[j + 1], vpow[sz]) % p) + p) % p;
    }

    long long getRh(int i, int j) {
        int sz = j - i + 1;
        return ((h1[j] - mul(h1[i - 1], vpow[sz] % p)) + p) % p;
    }
};

vector<int> v;
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    Hash h1(v, 200063, 44560482149LL);
    Hash h2(v, 200087, 188748146801LL);
    long long mx = 0;
    vector<int> ans;
    for (int k = 1; k <= n; ++k) {
        set<pair<long long, long long > > s;
        for (int i = 0, j = k; i <= n - k; i += k, j += k) {
            long long x1 = h1.getH(i,j - 1);
            long long x2 = h2.getH(i,j - 1);
            long long y1 = h1.getRh(i,j - 1);
            long long y2 = h2.getRh(i,j - 1);
            if(!s.count({x1,x2}) and !s.count({y1, y2})) s.insert({x1,x2});
        }
        if((int)s.size() > mx) { 
            mx = s.size();
            ans.clear();
            ans.push_back(k);
        } else if((int)s.size() == mx) ans.push_back(k);

    }

    cout << mx << " " << ans.size() << "\n";
    for (int x: ans)
        cout << x << " ";
    cout << "\n";

    return 0;
}
