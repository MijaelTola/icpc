#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int c[3010][3010];
long long dp[3010][3010][4];

long long f(int x, int y, int cur) {
    if(x == n - 1 and y == m - 1) {
        if(cur < 3) return c[x][y];
        else return 0;
    }

    long long &ans = dp[x][y][cur];
    if(ans != -1) return ans;
    ans = -1e15;

    if(cur < 3) {
        if(y + 1 < m) ans = max(ans, f(x, y + 1, cur + 1) + c[x][y]);
        if(x + 1 < n) ans = max(ans, f(x + 1, y, 0) + c[x][y]);
    }
    if(y + 1 < m) ans = max(ans, f(x, y + 1, cur));
    if(x + 1 < n) ans = max(ans, f(x + 1, y, 0));
    return ans;
}

int main() {

    memset(dp, -1, sizeof dp);
    cin >> n >> m >> k;

    for (int i = 0; i < k; ++i) {
        int x,y,w;
        cin >> x >> y >> w;
        x--,y--;
        c[x][y] = w;
    }

    cout << f(0,0, 0) << "\n";

    return 0;
}

