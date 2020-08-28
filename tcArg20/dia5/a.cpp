#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    int ans = 1e9;

    for (int i = 1; i <= n; ++i) {
        if(n % i == 0) {
            int x = i, y = n / i;
            ans = min(ans, 2 * x + 2 * y);
        }
    }
    cout << ans << "\n";
    return 0;
}

