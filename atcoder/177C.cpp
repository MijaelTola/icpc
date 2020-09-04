#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int main() {

    int n;
    cin >> n;

    vector<long long> v(n),b(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        b[i] = v[i];
    }

    long long ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        b[i] += b[i + 1];
        b[i] %= mod;
        ans += (b[i + 1] * v[i]) % mod;
        ans %= mod;
    }

    cout << ans << "\n";

    
    return 0;
}

