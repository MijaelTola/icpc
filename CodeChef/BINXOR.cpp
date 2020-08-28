#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

int t,n;
long long f[2000010];
char a[200010], b[200010];

int main() {
    
    auto mul = [] (long long a, long long b) {
        long long ans = 0;
        a %= mod;
        while(b) {
            if(b & 1) ans = (ans + a) % mod;
            a = (2 * a) % mod;
            b >>= 1;
        }
        return ans % mod;
    };

    auto modpow = [mul] (long long x, long long y) -> long long {
        long long res = 1;
        x = x % mod;
        while(y) {
            if(y & 1) res = mul(res, x) % mod;
            y >>= 1LL;
            x = mul(x,x);
        }
        return res;
    };
    
    auto C = [modpow, mul] (int m, int k) -> long long {
        assert(m >= k);
        return mul(f[m], modpow(mul(f[m - k], f[k]), mod - 2)) % mod;
    };

    f[0] = 1;
    
    for (long long i = 1; i < 2000010; ++i)
        f[i] = mul(i, f[i - 1]) % mod;
    
    auto solve = [C, mul] () -> long long{
        long long ans = 0;
        long long a1, b1;
        a1 = 0, b1 = 0;

        for (int i = 0; i < n; ++i) {
            a1 += a[i] == '1';
            b1 += b[i] == '1';
        }

        if(a1 == b1 and (!a1 or a1 == n)) return 1LL;
        
        long long mx = min(1ll * n, mul(2, n) - a1 - b1);

        for (int i = abs(a1 - b1); i <= mx; i += 2) 
            ans = (C(n, i) + ans) % mod;
        
        return ans;
    };

    
    scanf("%d", &t);

    while(t--) {
        scanf("%d %s %s", &n, a, b);
        printf("%lld\n", solve());
    }
    return 0;
}

