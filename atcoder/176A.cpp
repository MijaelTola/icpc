#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,x,t;
    cin >> n >> x >> t;

    int cur = 0;
    int ans = 0;
    while(cur < n) {
        cur += x;
        ans += t;
    }
    cout << ans << "\n";
    return 0;
}

