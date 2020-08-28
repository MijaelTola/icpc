#include <bits/stdc++.h>

using namespace std;

int a[160];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        memset(a, 0, sizeof a);
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[i] += x * 20;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[i] -= x * 10;
            ans = max(ans, max(a[i], 0));
        }
        cout << ans << "\n";
    }
    return 0;
}

