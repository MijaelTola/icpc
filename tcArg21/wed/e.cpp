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
        long long num = f[n];
        long long den = (f[(n - k + mod) % mod] * f[k]) % mod;
        return num * modpow(den, mod - 2) % mod;
    };

    int n,k;
    cin >> n >> k;

    cout << (1 << k) * C(2 * n, n) << "\n";
    //cout << C(n + 2 * m - 1, 2 * m) % mod << "\n";
    return 0;
}

