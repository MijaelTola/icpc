#include <bits/stdc++.h>

using namespace std;

int c[310][310];
int ans[310][310];
int n,m,k;

int main() {

    cin >> n >> m >> k;

    vector<pair<int,int> > v;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) {
            char x;
            cin >> x;
            if(x == '#') {
                v.emplace_back(i,j);
                c[i][j] = 1;
            }
        }


    int cur = 1;
    for (auto p: v) {
        int x = p.first, y = p.second;
        ans[x][y] = cur;
        y++;
        while(y < m and !c[x][y] and !ans[x][y]) ans[x][y++] = cur;
        x = p.first, y = p.second - 1;
        while(y >= 0 and !c[x][y] and !ans[x][y]) ans[x][y--] = cur;
        cur++;
    }

    
    for (int i = 0; i < n; ++i)
        if(ans[i][0] == 0) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = ans[i - 1][j];
            }
        }

    for (int i = n - 1; i >= 0; --i)
        if(ans[i][0] == 0) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = ans[i + 1][j];
            }
        }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
    return 0;
}

