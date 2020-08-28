#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int t,n,m,k;

pair<long long, long long> sum(pair<long long, long long> da , pair<long long, long long> db) {
    long long a = da.first;
    long long b = da.second;
    long long x = db.first;  
    long long y = db.second;   
    return {((a * y) % mod + (x * b) % mod) % mod,(b * y) % mod};
}

pair<long long, long long> mul(pair<long long, long long> da , pair<long long, long long> db) {
    long long a = da.first;
    long long b = da.second;
    long long x = db.first;  
    long long y = db.second;
    return {(a * x) % mod, (y * b) % mod};
}

long long modpow(long long a, long long b) {
    long long x = 1, y = a;
    while(b > 0) {
        if(b & 1) x = (x * y) % mod;
        y = (y * y) % mod;
        b /= 2;
    }
    return x % mod;
}
int main() {
    scanf("%d", &t);

    while(t--) {
        scanf("%d %d %d", &n, &k, &m);

        pair<long long, long long> ans = {0,1};
        pair<long long, long long> ac = {1, n};
        pair<long long, long long> wa = {1, n};
        pair<long long, long long> cur = ac;
        if(m == 1) {
            ans = {1,n};
        } else if(m == 2) {
            wa = {n - 1, n};
            cur = ac;
            ans = sum(ac, ans);
            ac = {1, ac.second + k};
            cur = mul(ac,wa);
            ans = sum(ans,cur);
        } else {
            long long in = (k * (m - 2) + n);
            long long a = 0;
            long long b = in + 1;
            while(b - a > 1) {
                long long mid = (a + b) / 2;
                if(k * mid <= in) a = mid;
                else b = mid;
            }
            for (int i = 0; i < a; ++i) {
                ans = sum(ans, cur);
                ac = {1, ac.second + k};
                cur = mul(ac, wa);
                wa = {wa.second - 1, wa.second};
            }
            ac = {1, ac.second - a * k};
            wa = {ac.second - 1, ac.second};
            cur = mul(ac,wa);
            ans = sum(ans,cur);
        }
        int g = __gcd(ans.first, ans.second);
        ans.first /= g;
        ans.second /= g;
        cout << ans.first << " " << ans.second << "\n";
        printf("%lld\n", ((long long)ans.first * modpow(ans.second, mod - 2)) % mod);
    }
    return 0;
}

