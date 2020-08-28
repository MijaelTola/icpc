#include <bits/stdc++.h>

using namespace std;

int v[1010];
int main() {
    
    int n,mx = 0, mn = 1e9;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
    }

    int ans = 1e9;
    for (int i = mn; i <= mx; ++i) {
        int tot = 0;
        for (int j = 0; j < n; ++j) {
            tot += (i - v[j]) * (i - v[j]);
        }
        ans = min(ans, tot);
    }
    cout << ans << "\n";
    return 0;
}

