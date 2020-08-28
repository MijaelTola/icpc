#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int n,k;
int v[100010];
long long f[100010];

int main() {

    f[0] = 1;

    for (int i = 1; i < 100010; ++i)
        f[i] = (i * f[i - 1]) % mod;

    auto modpow = [] (long long a, long long b) {
        long long x=1, y=a; 
        while (b > 0) {
            if (b & 1) 
                x = (x*y) % mod; 
            y = (y*y) % mod; 
            b /= 2;
        }
        return x % mod;
    };


    auto C = [modpow] (long long n, long long k) {
        if(k > n) return 0LL;
        return (f[n] * modpow( (f[k] * f[n - k]) % mod, mod - 2)) % mod;
    };


    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v, v + n);

    long long mn = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
        mn += (v[i] * C(n - i - 1, k - 1)) % mod;
        mx += (v[i] * C(i, k - 1)) % mod;
        mn %= mod;
        mx %= mod;
    }

    cout << (mx - mn + mod) % mod << "\n";
    return 0;
}

