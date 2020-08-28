#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long mul (long long a, long long b) {
    return (a * b) % mod;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    
     auto modpow = [] (long long a, long long b) {
        long long x = 1, y = a;
        while(b > 0) {
            if(b & 1) x = (x * y) % mod;
            y = (y * y) % mod;
            b >>= 1LL;
        }
        return x % mod;
    };

    int k = 1;
    while(t--) {
        long long n;
        cin >> n;

        long long mid = (n + 1) / 2;

        long long x = -1, y = -1;

        if(n & 1) {
            x = mid, y = mid;
        } else {
            x = mid, y = mid + 1;
        }

        n %= mod;
        x %= mod;
        y %= mod;
        auto get = [&] (long long x) {
            return mul(mul(x,(x + 1)), modpow(2, mod - 2)) % mod;
        };
     
        long long ini = y + 1;
        
        long long fin = get(y);

        auto s = [&] (long long l, long long r) {
            long long n = r - l + 1;
            return (mul(mul(mul(n, (n + 1)), (n + 2)), modpow(6, mod - 2)) + mul(mul(mul((l - 1), n), (n + 1)), modpow(2, mod - 2))) % mod;
        };
        
        long long cur = s(ini, ini + x - 2);
        
        long long sum = (get(fin) - get(fin - y) + mod) % mod;
    
        long long ans = ((cur * y) % mod + (sum * x) % mod) % mod;
        
        cout << "Case #" << k++ << ": "<< ans << "\n";

    }
    return 0;
}

