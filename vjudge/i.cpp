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
 
    auto C = [&] (int n, int k) {
        long long num = f[n];
        long long den = (f[(n - k + mod) % mod] * f[k]) % mod;
        return num * modpow(den, mod - 2) % mod;
    };
    
    cin >> n;
    
    long long ans = 0;

    for (int i = 2; i <= n; ++i) {
        long long dv = C(n - 1, i - 1);
        long long com = C(n, i);
        ans += (dv * com) % mod;
        ans %= mod;
    }
    cout << (2 * ans + n) % mod << "\n";
    return 0;
}
