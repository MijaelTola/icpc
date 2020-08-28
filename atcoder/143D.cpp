#include <bits/stdc++.h>

using namespace std;

int n;
int v[2010];
int main() {
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v, v + n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int pos = upper_bound(v, v + n, v[j] - v[i]) - v;
            ans += max(0, i - pos);
        }
    }
    cout << ans << "\n";

    return 0;
}

