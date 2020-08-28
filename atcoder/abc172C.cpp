#include <bits/stdc++.h>

using namespace std;

long long a[200010];
long long b[200010];
int main() {

    int n,m,k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < m; ++i)
        cin >> b[i];

    for (int i = 1; i < n; ++i)
        a[i] += a[i - 1];

    for (int i = 1; i < m; ++i)
        b[i] += b[i - 1];

    a[n] = b[m] = 1e9;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        long long dk = k - a[i];
        if(dk < 0) break;
        ans = max(ans, i + 1);
        int p = upper_bound(b, b + m, dk) - b;
        p--;
        ans = max(ans, p + i + 2);
    }

    for (int i = 0; i < m; ++i) {
        long long dk = k - b[i];
        if(dk < 0) break;
        ans = max(ans, i + 1);
        int p = upper_bound(a, a + n, dk) - a;
        p--;
        ans = max(ans, p + i + 2);
    }
    cout << ans << "\n";
    return 0;
}

