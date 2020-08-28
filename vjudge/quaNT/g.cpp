#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 9;

int main() {

    auto modpow = [] (int a, int b) {
        long long x = 1, y = a;
        while(b) {
            if(b & 1) x = (x * y) % mod;
            y = (y * y) % mod;
            b >>= 1;
        }
        return x % mod;
    };

    long long n,a,b,k;
    string s;
    cin >> n >> a >> b >> k >> s;
    

    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        long long cur = (modpow(a, n - i) * modpow(b, i)) % mod;
        cur %= mod;
        if(s[i] == '+') ans += cur;
        else ans -= cur;
        ans += mod;
        ans %= mod;
    }
    
    long long m = (n + 1) / k;
    long long r = (modpow(modpow(a, k), mod - 2)* modpow(b,k)) % mod;
    if(r == 1) {
        ans = (ans * m) % mod;
    } else {
        long long num = (1 - modpow(r, m) + mod) % mod;
        long long den = (1 - r + mod) % mod;
        ans = ans * ((num * modpow(den, mod - 2)) % mod) % mod;
        ans %= mod;
    }


    cout << ans << "\n";

    return 0;
}

