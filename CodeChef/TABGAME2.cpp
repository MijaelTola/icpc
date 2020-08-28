#include <bits/stdc++.h>

using namespace std;

bool c[1010][1010];

int main(){
    //ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        memset(c, 0, sizeof c);
        int n,m,q; 
        string dx,dy;
        cin >> dx >> dy;
        n = dx.size();
        m = dy.size();
        c[0][0] = (dx[0] == '0' or dy[0] == '0');
        for (int i = 1; i < n; ++i) 
            c[0][i] = !c[0][i - 1] or dx[i] == '0';

        for (int i = 1; i < m; ++i) 
            c[i][0] = !c[i - 1][0] or dy[i] == '0';

        for (int i = 1; i < max(n,m); ++i) {
            for (int j = 1; j < n; ++j) 
                c[i][j] = (!c[i - 1][j] or !c[i][j - 1]);
            for (int j = 1; j < m; ++j) 
                c[j][i] = (!c[j - 1][i] or !c[j][i - 1]);
        }

        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; ++j)
                if(c[i][j]) cout << "1 ";
                else cout << "2 ";
            cout << "\n";
        }
        cin >> q;
        while(q--) {
            int x,y;
            cin >> x >> y;
            x--,y--;
            cout << c[x][y];
        }
        cout << "\n";
    }
    return 0;

}
