#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int main() {

    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &x: v)
        cin >> x;

    sort(v.begin(), v.end());
    long long ans = 1;
    for (int i = 0; i < n; ++i) {
        ans *= (v[i] - i);
        if(v[i] - i <= 0) return cout << "0\n", 0;
        ans %= mod;
    }
    cout << ans << "\n";
    return 0;
}
