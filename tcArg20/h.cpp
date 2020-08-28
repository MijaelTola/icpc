#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9 + 7;
long long f[101000];
int n,m;
 
int main() {
 
    
    f[0] = 1;
 
    for (int i = 1; i < 101000; ++i)
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
        if(k > n) return 0LL;
        long long num = f[n];
        long long den = (f[(n - k + mod) % mod] * f[k]) % mod;
        return (num * modpow(den, mod - 2)) % mod;
    };

    int n,m,k;
    cin >> n >> m >> k;

    cout << (C(n - 1, 2 * k) * C(m - 1, 2 * k)) % mod << "\n";
    return 0;
}
