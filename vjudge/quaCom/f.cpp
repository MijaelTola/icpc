#include <bits/stdc++.h>

using namespace std;

long long f[300010];

int main() {

    long long n,mod;
    cin >> n >> mod;
    
    f[0] = 1;

    for (int i = 1; i < 300010; ++i)
        f[i] = (i * f[i - 1]) % mod;

    long long ans = 0;

    for (int i = 1; i <= n; ++i) {
        ans += (n - i + 1) * (f[i] * f[n - i + 1] % mod);
        ans %= mod;
    }

    cout << ans << "\n";

    return 0;
}
