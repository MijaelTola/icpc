#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
long long f[201000];
int n,m;

int main() {
    
    f[0] = 1;
 
    for (int i = 1; i < 201000; ++i)
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
 
    auto r = [&] (long long x, long long p) {
        long long num = (1 - modpow(x, (p + mod) % mod) + mod) % mod;
        long long dem = (1 - x + mod) % mod;
        dem = modpow(dem, mod - 2);
        return (num * dem) % mod;
    };

    cin >> n >> m;
    

    long long ans = 0;
    for (int i = 1; i <= m + 1; ++i) {
        long long cur = n % mod;
        int a = n - i;
        int b = a / i;
        if(a % i) b++;
        cout << i << ": " << a << " " << b << "\n";
        long long current = (r(n - 1, a) - r(n - 1, (b - 1 + mod) % mod) + mod) % mod;
        cout << i << " "<< r(n - 1, a) << " gg\n";
        ans +=  n * current % mod;
        ans %= mod;
    }

    cout << ans << "\n";
    return 0;
}

