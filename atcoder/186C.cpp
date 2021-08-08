#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    int ans = 0;

    auto has = [&] (int x) {
        bool flag = 0;
        while(x > 0) {
            flag |= x % 10 == 7;
            x/=10;
        }
        return !flag;
    };

    auto to_octal = [&] (int x) {
        int ans = 0;
        while(x > 0) {
            ans = ans * 10 + x % 8;
            x/=8;
        }
        return ans;
    };

    for (int i = 1; i <= n; ++i)
        ans += has(i) and has(to_octal(i));

    cout << ans << "\n";
    return 0;
}

