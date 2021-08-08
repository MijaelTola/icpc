#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    map<int,int> mp;

    for (auto &x: v)
        cin >> x;

    long long ans = 0;
    int ini = 0;

    auto get = [&] (long long x) {
        return x * (x + 1) / 2;
    };

    for (int i = 0; i < n; ++i) {
        if(mp.count(v[i]) and mp[v[i]] >= ini) {
            int l = mp[v[i]];
            ans += get(i - ini) - get((i - l) - 1);
            ini = l + 1;
        }
        mp[v[i]] = i;
    }

    ans += get(n - ini);
    cout << ans << "\n";
    return 0;
}
