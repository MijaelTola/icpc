#include <bits/stdc++.h>

using namespace std;

int dp[11][2][10][10];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    int k = 0;
    while(t--) {
        int a,b;
        cin >> a >> b;
        a--;
        string x,y;
        x = to_string(a);
        y = to_string(b);

        auto f = [] (int k, string s) {
            memset(dp, 0, sizeof dp);
            int sz = s.size();
            for (int i = 0; i < 10; ++i) {
                dp[sz][1][i][k] = 1;
                dp[sz][0][i][k] = 1;
            }

            for (int pos = sz - 1; pos >= 0; pos--) {
                for (int flag = 0; flag < 2; ++flag) {
                    for (int last = 0; last < 10; ++last) {
                        for (int cur = 0; cur < 10; ++cur) {
                            int lim = 9;
                            if(flag) lim = s[pos] - '0';
                            for (int i = 0; i <= lim; ++i) {
                                if(last < i) dp[pos][flag][last][cur] += dp[pos + 1][i == lim and flag][i][cur + 1];
                                dp[pos][flag][last][cur] += dp[pos + 1][i == lim and flag][last][cur];
                            }
                        }
                    }
                }
            }
            return dp[0][1][0][0];
        };
        
        int id = y.size() - 1;
        int ans = -1;

        while(id--) {
            ans = f(id, y) - f(id, x);
            if(ans) break;
        }
        
        cout << "Case " << ++k << ": "  << id << " " << ans << "\n";
    }
    return 0;
}

