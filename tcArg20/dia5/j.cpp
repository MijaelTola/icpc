#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int a,b,c;

    cin >> a >> b >> c;
    
    int mn = min({a,b,c});
    int mx = max({a,b,c});

    int ans = 1e9;

    for (int i = mn; i <= mx; ++i) {
        int x = abs(i - a);
        int y = abs(i - b);
        int z = abs(i - c);
        ans = min(ans, x + y + z);
    }

    cout << ans << "\n";

    return 0;
}

