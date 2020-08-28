#include <bits/stdc++.h>

using namespace std;

int n,m;
char c[110][110];

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m;

        for (int i = 0; i < n; ++i) {
            for (int j = 0;  j < m; ++j)
                cin >> c[i][j];
        }
    
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            ans += c[i][m - 1] == 'R';
        }

        for (int i = 0; i < m; ++i) {
            ans += c[n - 1][i] == 'D';
        }

        cout << ans << "\n";
    }
    return 0;
}

