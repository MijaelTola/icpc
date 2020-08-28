#include <bits/stdc++.h>

using namespace std;

bool c[100010];
bool dc[100010];
bool c2[100010];
bool dc2[100010];

bool get(bool xx) {
    if(xx) return 1;
    return 2;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        memset(c, 0, sizeof c);
        memset(c2, 0, sizeof c2);
        memset(dc, 0, sizeof dc);
        memset(dc2, 0, sizeof dc2);
        int n,m,q; 
        string dx,dy;
        cin >> dx >> dy;
        n = dx.size();
        m = dy.size();
        c[0] = (dx[0] == '0' or dy[0] == '0');
        c2[0] = (dx[0] == '0' or dy[0] == '0');

        for (int i = 1; i < n; ++i) 
            c[i] = (!c[i - 1] or dx[i] == '0');
        
        for (int i = 1; i < m; ++i) 
            c2[i] = (!c2[i - 1] or dy[i] == '0');
        
        dc[0] = c2[1];
        dc2[0] = c[1];
        
        for (int i = 1; i < n; ++i) 
            dc[i] = !dc[i - 1] or !c[i];
        for (int i = 1; i < m; ++i)
            dc2[i] = !dc2[i - 1] or !c2[i];
    
       
        cin >> q;
        while(q--) {
            int x,y;
            cin >> x >> y;
            if(x == 1 or y == 1) {
                x--,y--;
                if(x == 0) cout << c[y];
                else cout << c2[x];
                continue;
            }
            int xx = x - min(x,y);
            int yy = y - min(x,y);
            bool ans = 0;
            if(xx == 0) cout << dc[yy + 1];
            else cout << dc2[xx + 1];
        }
        cout << "\n";
    }
    return 0;
}

