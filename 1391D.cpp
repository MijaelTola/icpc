#include <bits/stdc++.h>

using namespace std;

int n,m;

int main() {
    
    cin >> n >> m;

    char v[n + 10][m + 10];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }
    
    if(n == 1 or m == 1) return cout << "0\n", 0;
    if(n > 3) return cout << "-1\n", 0;
    
    auto check = [&] (int x, int y, int sz) {

        int cnt = 0;
        for (int i = 0; i <= 1; ++i) {
            cnt += !!(x & (1 << i));
            cnt += !!(y & (1 << i));
        }
        int cnt2 = 0;

        if(sz == 3) {
            for (int i = 1; i <= 2; i++) {
                cnt2 += !!(x & (1 << i));
                cnt2 += !!(y & (1 << i));
            }
        } else cnt2 = 1;
        return cnt % 2 != 0 and cnt2 % 2 != 0;
    };
    
    if(n < 4) {
        int dp[m + 100][20];
        memset(dp, 0, sizeof dp);
        for (int pos = m - 1; pos >= 0; pos--) {
            for (int last = 0; last < 8; ++last) {
                dp[pos][last] = 1e9;
                for (int cur = 0; cur < (1 << n); ++cur) {
                    int cost = 0;
                    for (int i = 0; i < n; ++i) {
                        int val = !!(cur & (1 << i));
                        int mat = v[i][pos] - '0';
                        if(val != mat) cost++;
                    }
                    
                    if(check(last,cur, n) or pos == 0) {
                        dp[pos][last] = min(dp[pos][last], dp[pos + 1][cur] + cost);
                    }
                }
            }
        }
        
        cout << dp[0][0] << "\n";

    } 

    return 0;
}

