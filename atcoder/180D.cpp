#include <bits/stdc++.h>

using namespace std;

int main() {
    long long x, y, a, b;
    cin >> x >> y >> a >> b;
    long long ans = 0;
    while (1) {
        if (y/a < x) break;
        if (a*x >= y) break;
        if (a*x >= x+b) break;
        x *= a;
        ++ans;
    }
    ans += (y-1-x)/b;
    cout << ans << endl;
    return 0;
}
