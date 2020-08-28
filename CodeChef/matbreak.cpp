#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

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
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        long long a;
        cin >> n >> a;

        int c = 1;
        long long ans = 0;
        for (int i = 1; i < n; ++i, c += 2) {
            ans += modpow(a, c);
            ans %= mod;
            a = modpow(a, c + 1);
        }
        ans += modpow(a, c);
        ans %= mod;
        cout << ans << "\n";
    }
    return 0;
}

