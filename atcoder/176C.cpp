#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    int last = 0;
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x < last) ans += abs(x - last);
        last = max(last, x);
    }

    cout << ans << "\n";
    return 0;
}

