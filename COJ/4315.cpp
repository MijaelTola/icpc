#include <bits/stdc++.h>

using namespace std;

long long m,k;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> m >> k) {
        long long cur = 1LL;
        for (int i = 1; i < k; ++i) {
            cur <<= 1LL;
            cur |= (1LL << 0);
        }
        while(cur < m) cur <<= 1LL;
        cout << cur << "\n";
    }
    return 0;
}

