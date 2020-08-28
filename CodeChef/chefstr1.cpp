#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;
        vector<int> v(n);

        for (auto &x: v)
            cin >> x;

        long long ans = 0;
        for (int i = 1; i < (int)v.size(); ++i)
            ans += abs(v[i] - v[i - 1]) - 1;

        cout << ans << "\n";
    }

    return 0;
}

