#include <bits/stdc++.h>

using namespace std;

int n,m,p1,p2;
int dp[110][1010][1010][2];

int f(int pos, int c1, int c2, bool flag, string a) {
    if(pos == n) {
        if(c1 == p1 and c2 == p2 and flag) {
            cout << a << "\n";
            return 1;
        }
        return 0;
    }
    if(dp[pos][c1][c2][flag]) return dp[pos][c1][c2][flag];
    flag = 1;
    if(c1 > p1 or c2 > p2) return 0;
    int ans = 0;

    for (int i = 0; i <= m; ++i) {
        ans += f(pos + 1, c1 + i, c2, flag, a + "| 1" + ": " + to_string((c1 + i)));
        ans += f(pos + 1, c1, c2 + i, flag, a + "| 2" + ": " + to_string((c2 + i)));
    }

    return ans;
}

int main() {
    memset(dp, -1,sizeof dp);
    cin >> n >> m >> p1 >> p2;
    cout << f(0,0,0,0,"") << "\n";
    return 0;
}

