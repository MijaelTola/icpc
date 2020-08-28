#include <bits/stdc++.h>

using namespace std;

int t,n;

char v[3][1010];
int dp[3][1010][2];

const int mod = 1e9 + 7;

int f(int x,int y, bool flag) {
    if(x == 2 and y == n - 1) return 1;
    int ans = 0;
    if(x < 0 or y < 0 or x == 3 or y == n) return 0;
    if(v[x][y] == '#') return 0;
    if(dp[x][y][flag] != -1) return dp[x][y][flag];
    if(flag) {
        ans = (ans + f(x + 1, y, !flag)) % mod;
        ans = (ans + f(x - 1, y, !flag)) % mod;
    } else ans = (ans + f(x, y + 1, !flag)) % mod;
    return dp[x][y][flag] = ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    int k = 0;
    while(t--) {
        memset(dp, -1,sizeof dp);
        cin >> n;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < n; ++j)
                cin >> v[i][j];
        cout << "Case #" << ++k << ": "<< f(0,0,1) << "\n";
    }
    return 0;
}

