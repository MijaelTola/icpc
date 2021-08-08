#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    vector<long long> v(n);

    long long sum = 0;

    for (auto &x: v) {
        cin >> x;
        sum += x;
    }
    sort(v.rbegin(), v.rend());

    long long ans = 0;
    for (int i = 0, j = n - 1; i < n; ++i, j--) {
        sum -= v[i];
        ans += abs(1LL * v[i] * j - sum);

    }

    cout << ans << "\n";
    return 0;
}

