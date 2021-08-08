#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9 + 7;
long long f[1001000];
int n,m;
 
int main() {
 
    
    f[0] = 1;
 
    for (int i = 1; i < 1001000; ++i)
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
        long long den = (f[n - k] * f[k]) % mod;
        return num * modpow(den, mod - 2) % mod;
    };

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        n--;
        cout << C(2 * n + 1, n + 1) % mod << "\n";
    }
    return 0;
}
