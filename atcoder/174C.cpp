#include <bits/stdc++.h>

using namespace std;

int main() {

    long long x;
    cin >> x;

    long long cur = 7 % x;
    int ans = 1;

    while(cur != 0 and ans < 1e8) {
        cur = (cur * 10 + 7) % x;
        ans++;
    }

    if(ans == 1e8) cout << "-1\n";
    else cout << ans << "\n";
    return 0;
}

