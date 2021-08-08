#include <bits/stdc++.h>

using namespace std;

long long ans[1000100];

int main() {
    
    ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    auto get = [&] (long long x) {
        return x * (x + 1) / 2;
    };

    for (int i = 1; i < 1000100; ++i) {
        ans[i] = ans[i - 1] + get(i);
    }

    int t;
    cin >> t;

    while(t--) {
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }
    return 0;
}

