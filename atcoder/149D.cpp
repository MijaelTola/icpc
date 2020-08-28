#include <bits/stdc++.h>

using namespace std;

int n,k,r,s,p;
string t, cur;
char m[] = {'r', 's', 'p'};
int v[3];
long long dp[100010][3];

int main() {
    auto win = [] (char x, char y) {
        if(x == 'r' and y == 's') return 1;
        if(x == 's' and y == 'p') return 1;
        if(x == 'p' and y == 'r') return 1;
        return 0;
    };

    auto f = [&win]() {

        for (int i = 0; i <= (int)cur.size(); ++i)
            dp[i][0] = dp[i][1] = dp[i][2] = 0;

        for (int i = cur.size() - 1; i >= 0; i--) {
            for (int k = 0; k < 3; ++k) {
                for (int j = 0; j < 3; ++j) {
                    if(k == j) continue;
                    if(win(m[j], cur[i])) dp[i][k] = max(dp[i][k], dp[i + 1][j] + v[j]);
                    else dp[i][k] = max(dp[i][k], dp[i + 1][j]);
                }
            }
        }
        return max({dp[0][0], dp[0][1], dp[0][2]});
    };

    cin >> n >> k >> v[0] >> v[1] >> v[2] >> t;

    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        cur = "";
        for (int j = i; j < (int)t.size(); j += k) 
            cur += t[j];
        ans += f();
    }
    cout << ans << "\n";
    return 0;
}

