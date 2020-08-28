#include <bits/stdc++.h>

using namespace std;

int n,m;
char v[110][110];
int dp[110][110];

int f(int x, int y) {
    if(x == n and y == m) return 0;
    
    int &ans = dp[x][y];
    if(ans != -1) return ans;
    ans = 1e9;
    if(x + 1 <= n) 
        ans = min(ans, f(x + 1, y) + (v[x + 1][y] == '#'));

    if(y + 1 <= m) 
        ans = min(ans, f(x, y + 1) + (v[x][y + 1] == '#'));

    return ans;
}
int main() {
    memset(dp, -1, sizeof dp);

    cin >> n >> m;

    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= m; ++j)
            cin >> v[i][j];
    }
    cout << f(1,1) + (v[1][1] == '#') << "\n";
    return 0;
}

