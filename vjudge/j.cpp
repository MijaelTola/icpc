#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9 + 7;
long long f[1001000];
long long n,m;
 
int main() {
 
    
    f[0] = 1;
 
    for (int i = 1; i < 1001000; ++i)
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
        return num * modpow(den, mod - 2) % mod;
    };

    int n,m;
    cin >> n >> m;

    long long ans = modpow(m,n);

    for (int i = 0; i <= n; ++i) {
        ans += ((modpow(m, i) * modpow(m - 1, n - i)) % mod * C(n, i - 1)) % mod;
        ans %= mod;
    }


    cout << ans << "\n";
    return 0;
}
