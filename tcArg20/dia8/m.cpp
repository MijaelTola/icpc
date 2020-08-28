#include <bits/stdc++.h>

using namespace std;

int c[110][110];

int main() {
    
    int n,m,d;
    cin >> n >> m >> d;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> c[i][j];

    long long ans = 1e11;

    for (int k = 0; k <= 10000; ++k) {
        
        long long cur = 0;
        bool flag = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int df = abs(c[i][j] - k);
                if(df % d == 0) {
                    cur += df / d;
                } else {
                    flag = 0;
                    goto fin;
                }
            }
        }
        fin:
        if(flag) ans = min(ans, cur);
    }
    if(ans == 1e11) cout << "-1\n";
    else cout << ans << "\n";
    return 0;
}

