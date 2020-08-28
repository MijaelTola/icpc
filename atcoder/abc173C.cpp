#include <bits/stdc++.h>

using namespace std;

char c[8][8];
char c2[8][8];
int main() {
 
    int n,m,k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> c[i][j];

    int ans = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int mask2 = 0; mask2 < (1 << m); mask2++) {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j) {
                    c2[i][j] = c[i][j];
                    if((mask & (1 << i)) or (mask2 & (1 << j)))
                        c2[i][j] = 'r';
                }

            int cur = 0;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j) 
                    cur += c2[i][j] == '#';

            ans += cur == k;
        }
    }

    cout << ans << "\n";

    return 0;
}

