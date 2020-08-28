#include <bits/stdc++.h>

using namespace std;


int main() {
    
    int a,b;

    cin >> a >> b;


    auto get = [&] (int x) {
        int ans = 0;
        while(x > 0) {
            ans += x % 10;
            x /= 10;
        }
        return ans;
    };

    int ans = 1;
    for (int i = 0; i < b; ++i) {
        ans = get(ans) * a;
    }

    while(ans >= 10) ans = get(ans);

    cout << ans << "\n";

    return 0;
}

