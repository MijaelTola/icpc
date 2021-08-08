#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long n;

    cin >> n;

    int ans = 0;
    auto f = [&] (int i) {
        string x = to_string(i);
        x = x + x;
        long long s = 0;

        for (auto c: x)
            s = s * 10 + (c - '0');
        return s;
    };

    for (int i = 1; f(i) <= n; ++i) {
        ans++;
    }
    cout << ans << "\n";
    return 0;
}

