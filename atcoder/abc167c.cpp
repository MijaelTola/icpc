#include <bits/stdc++.h>

using namespace std;

int c[13];
int d[13][13];
long long cur[13];

int main() {

    int n,m,k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        for (int j = 0; j < m; ++j) 
            cin >> d[i][j];
    }

    int ans = 1e9;
    for (int i = 0; i < (1 << n); ++i) {
        memset(cur, 0, sizeof cur);
        int total = 0;
        for (int j = 0; j < n; ++j) {
            if(i & (1 << j)) {
                for (int l = 0; l < m; ++l) 
                    cur[l] += d[j][l];
                total += c[j];
            }
        }
        
        bool flag = 1;
        for (int j = 0; j < m; ++j) {
            flag &= cur[j] >= k;
        }

        if(flag) ans = min(ans, total);

    }
    if(ans == 1e9) cout << "-1\n";
    else cout << ans << "\n";
    return 0;
}

