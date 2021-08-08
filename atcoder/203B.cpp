#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,m;
    cin >> n >> m;

    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int cur = i * 100 + j;
            ans += cur;
        }
    }

    cout << ans << "\n";

    return 0;
}

