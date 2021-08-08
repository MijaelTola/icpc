#include <bits/stdc++.h>

using namespace std;

int n,m;
char c[2010][2010];
int dp[2010][2010][2];

int f(int x, int y, int turn) {
    if(x == n - 1 and y == m - 1) return 0;
    
    if(dp[x][y][turn] != -1) return dp[x][y][turn];
    if(turn) {
        int r = -1e9, d = -1e9;
        if(x + 1 < n) 
            d = f(x + 1, y, 1 - turn);
        if(y + 1 < m) 
            r = f(x, y + 1, 1 - turn);
        
        if(c[x + 1][y] == '+') d++;
        else d--;
        if(c[x][y + 1] == '+') r++;
        else r--;
        
        return dp[x][y][turn] = max(r, d);
    } else {
        int r = 1e9, d = 1e9;
        if(x + 1 < n) 
            d = f(x + 1, y, 1 - turn);
        if(y + 1 < m) 
            r = f(x, y + 1, 1 - turn);
        
        if(c[x + 1][y] == '-') d++;
        else d--;
        if(c[x][y + 1] == '-') r++;
        else r--;
        return dp[x][y][turn] = min(r, d);
    }
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> c[i][j];
    
    int res = f(0,0,1);
    if(res > 0) cout << "Takahashi\n";
    else if(res == 0) cout << "Draw\n";
    else cout << "Aoki\n";
    return 0;
}

