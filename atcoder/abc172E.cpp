#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
long long f[501000];
int n,m;

int main() {

    cin >> n >> m;

    f[0] = 1;

    for (int i = 1; i < 501000; ++i)
        f[i] = (i * f[i - 1]) % mod;

    auto modpow = [] (int a, int b) {
        long long x = 1, y = a;
        while(b) {
            if(b & 1) x = (x * y) % mod;
            y = (y * y) % mod;
            b >>= 1;
        }
        return x % mod;
    };

    auto C = [modpow] (int n, int k) {
        long long num = f[n];
        long long den = (f[(n - k + mod) % mod] * f[k]) % mod;
        return (num * modpow(den, mod - 2)) % mod;
    };

    long long p = (C(m,n) * f[n]) % mod;
    
    long long ans = (p * p) % mod;
    cout << ans << " ini\n";
    for (int i = 1; i <= n; ++i) {
        long long c = (f[n] * C(m, i)) % mod;
        cout << c << "\n";
        ans = (ans - c + mod) % mod;
    }
    cout << ans << "\n";
    return 0;
}
