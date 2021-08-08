#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int a,b,c;
    cin >> a >> b >> c;

    int ans = 0;

    auto ct = [&] (int x) {
        while(x > 0) {
            int m = x % 10;
            ans += m == c;
            x /= 10;
        }
        return ans;
    };

    for (int i = a; i <= b; ++i) {
        ct(i);
    }
    cout << ans << "\n";
    return 0;
}

