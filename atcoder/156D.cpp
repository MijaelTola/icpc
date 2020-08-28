#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
long long f[200010];

int main() {
    
    f[0] = 1;

    for (int i = 1; i < 200010; ++i)
        f[i] = (f[i - 1] * i) % mod;
    
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
        n %= mod;
        long long num = f(n);
        long long den = (f(n - k + mod) % mod] * f(k)) % mod;
        return num * modpow(den, mod - 2) % mod;
    };
    int n,a,b;
    cin >> n >> a >> b;

    return 0;
}

