#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    
    int ans = -1e9;
    for (int i = a; i <= b; ++i) {
        for (int j = c; j <= d; ++j) {
            ans = max(ans, i - j);
        }
    }
    cout << ans << "\n";
    return 0;
}

