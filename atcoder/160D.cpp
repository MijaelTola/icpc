#include <bits/stdc++.h>

using namespace std;

int n,x,y;
int main() {

    cin >> n >> x >> y;


    for (int i = 1; i < n; ++i) {
        int d1 = (n - y) + x - 1;
        int d2 = (y - x + 1);
        int ans = max(0, d1 - i);
        ans += max(0, d2 - i);
        cout << ans << "\n";
    }
    return 0;
}

