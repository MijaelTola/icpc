#include <bits/stdc++.h>

using namespace std;

int n;
int v[25][200010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> n) {

        for (int i = 0; i < 25; ++i)
            for (int j = 0; j <= n; ++j)
                v[i][j] = 0;
        
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            v[x][i] = 1;
        }
        
        for (int i = 0; i < 25; ++i) 
            for (int j = 1; j <= n; ++j) 
                v[i][j] += v[i][j - 1];

        int q;
        cin >> q;

        while(q--) {
            int l,r;
            cin >> l >> r;
            int ans = 0;
            
            for (int i = 0; i < 25; ++i) 
                ans += v[i][r] - v[i][l - 1] != 0;
            cout << ans << "\n";
        }

    }
    return 0;
}

