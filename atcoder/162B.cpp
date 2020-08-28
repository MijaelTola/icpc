#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    long long ans = 0;

    for (long long i = 1; i <= n; ++i) {
        if(i % 3 == 0 or i % 5 == 0) {}
        else {
            ans += i;
        }
    }
    cout << ans << "\n";
    return 0;
}

