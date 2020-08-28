#include <bits/stdc++.h>

using namespace std;

long long d;
const int mod = 1e9 + 7;
int main() {
    
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
 
    while(t--) {
        cin >> d;
            
        long long cnt = 0;

        long long p = 2;
        for (long long i = 1; i <= d + 1; ++i) {
            cnt += ((long long) (i * (modpow(2, mod - 2))  * p) % mod) % mod;
            cnt %= mod;
            p = (p * 2) % mod;
        }
        cout << cnt << "\n";
        long long total = 1;

        for (int i = 0; i <= d; ++i) 
            total = (total * 2) % mod;

        total = (total - 1 + mod) % mod;
        total = ((total * (total - 1 + mod) % mod) % mod);;
        total = (total * modpow(2, mod - 2)) % mod;
        total *= 4;
        cout << (cnt * modpow(total, mod - 2)) % mod << "\n";
    }
    return 0;
}

