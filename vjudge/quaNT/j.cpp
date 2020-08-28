#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int main() {
    
    long long n,m;
    scanf("%lld %lld", &n, &m);

    long long ans = 0;

    auto get = [] (long long a, long long b) {
        b = (b - a) % mod;
        a %= mod;
        long long cur = (b * (b + 1) / 2) % mod;
        return (cur + (a * b) % mod) % mod;
    };
    long long i;
    for (i = 1; i * i < n and i <= m; ++i) {
        ans += ((n / i) * i) % mod;
        ans %= mod;
    }

    for (i = n / i; i >= n / m and i >= 1; i--) {
        ans += (get(n / (i + 1) , min(m, n / i)) * i) % mod;
        ans %= mod;
    }
    
    ans = (((m % mod) * (n % mod)) % mod - ans + mod) % mod;
    printf("%lld\n", ans);
    return 0;
}

