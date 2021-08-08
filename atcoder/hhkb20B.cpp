#include <bits/stdc++.h>

using namespace std;

char s[110][110];
int n,m;

int main() {
    
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> s[i][j];

    int ans = 0;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            ans += s[i][j] == '.' and s[i][j + 1] == '.';
            ans += s[i][j] == '.' and s[i + 1][j] == '.';
        }

    cout << ans << "\n";
    return 0;
}

