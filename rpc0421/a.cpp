#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v(n);

    for (auto &x: v)
        cin >> x;

    sort(v.begin(), v.end());
    

    int last = -1;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if(last + 1 < v[i]) ans += v[i];
        last = v[i];
    }

    cout << ans << "\n";
    return 0;
}

