#include <bits/stdc++.h>

using namespace std;
long long f[1000100];
long long p[1000100];
const int mod = 1e9 + 7;

int main() {
    
    int n;
    cin >> n;

    f[0] = 1;
    p[0] = 1;
    for (int i = 1; i < 1000010; ++i) {
        f[i] = (i * f[i - 1]) % mod;
        p[i] = (p[i - 1] * 2) % mod;
    }

    long long res = (f[n] - p[n - 1] + mod) % mod;
    cout << res << "\n";
    return 0;
}

