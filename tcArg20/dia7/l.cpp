#include <bits/stdc++.h>

using namespace std;

int n,m;
int c[55][55];

int main() {
    memset(c, 0, sizeof c);
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> c[i][j];
            if(i > 0) c[i][j] += c[i - 1][j];
            if(j > 0) c[i][j] += c[i][j - 1];
            if(i > 0 and j > 0) c[i][j] -= c[i - 1][j - 1];
        }

    int a,b;
    cin >> a >> b;
    int ans = 1e9;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int k = i + a - 1;
            int l = j + b - 1;

            if(k < n and l < m) {
                int cur = c[k][l];
                if(i) cur -= c[i - 1][l];
                if(j) cur -= c[k][j - 1];
                if(i and j) cur += c[i - 1][j - 1];
                ans = min(ans, cur);
            }


            k = i + b - 1;
            l = j + a - 1;
            
            if(k < n and l < m) {
                int cur = c[k][l];
                if(i) cur -= c[i - 1][l];
                if(j) cur -= c[k][j - 1];
                if(i and j) cur += c[i - 1][j - 1];
                ans = min(ans, cur);
            }
        }
    }

    cout << ans << "\n";


    return 0;
}

