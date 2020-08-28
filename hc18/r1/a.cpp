#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
long long dp[3][1010][4];
char c[3][1010];
int n;
bool ver(int x, int y) {
    return x >= 0 and y >= 0 and x < 3 and y < n and c[x][y] != '#';
}
long long f(int x, int y, int cur) {
    if(x == 0 and y == 0) return cur;
    long long &ans = dp[x][y][cur];
    if(ans != -1) return ans;
    ans = 0;
    if(!cur) {
        if(ver(x - 1, y)) ans += f(x - 1, y,1), ans %= mod;
        if(ver(x + 1, y)) ans += f(x + 1, y,1), ans %= mod;
    } else if(ver(x, y - 1)) ans += f(x, y - 1, 0);
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    int k = 1;
    while(t--) {
        memset(dp, -1, sizeof dp);
        cin >> n;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < n; ++j)
                cin >> c[i][j];
        
        cout  << "Case #" << k++ << ": ";
        if(ver(2, n - 1)) cout << f(2,n - 1, 0) << "\n";
        else cout << "0\n";
    }
    return 0;
}
