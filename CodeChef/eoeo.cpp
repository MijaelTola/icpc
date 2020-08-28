#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        long long x;
        cin >> x;
        if(x & 1LL) {
            cout << x / 2 << "\n";
        } else {
            long long dx = x;
            long long cur = 1LL;
            while(x % 2 == 0) {
                x >>= 1LL;
                cur <<= 1LL;
            }
            cur <<= 1LL;
            cout << dx / cur << "\n";
        }

    }
    return 0;
}

