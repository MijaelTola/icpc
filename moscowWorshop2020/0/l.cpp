#include <bits/stdc++.h>

using namespace std;

int a,b,n;

int dp[2][43][21][21][21][2];

int main() {

    cin >> n >> a >> b;

    vector<int> v(n),v2(n);

    for (int &x: v) cin >> x;

    for (int &x: v2) cin >> x;
    

    int last = 0;

    auto set = [] (int cur, int val) {
    for (int i = 0; i < 43; ++i)
        for (int j = 0; j < 21; ++j)
            for (int k = 0; k < 21; ++k)
                for (int l = 0; l < 21; ++l) {
                    dp[cur][i][j][k][l][1] = val;
                    dp[cur][i][j][k][l][0] = val;
                }
    };

    set(1, 1e9);
    
    for (int i = n - 1; i >= 0; i--) {
        int cur = 1 - last;
        set(cur, 1e9);
        for (int j = 0; j <= 2 * a; ++j) {
            for (int k = 0; k <= b; ++k) {
                for (int l = 0; l <= a; ++l) {
                    for (int m = 0; m <= b; ++m) {
                        for (int r = 0; r < 2; ++r) {
                            int &ans = dp[cur][j][k][l][m][r];

                            int dm = max(0, m - 1);
                            int dk = max(0, k - 1);
            
                            if(v[i] and v2[i]) {
                                if(j and k and l and m) 
                                    ans = min(ans, dp[last][j - 1][k - 1][l - 1][m - 1][r]);
                                else if(j and k) 
                                    ans = min(ans, dp[last][j - 1][k - 1][a - 1][b - 1][r] + 1);
                                else if(l and m) {
                                    ans = min(ans, dp[last][a - 1][b - 1][l - 1][m - 1][0] + 1);
                                    ans = min(ans, dp[last][2 * a - 1][b - 1][l - 1][m - 1][1] + 2);
                                }

                                if(j >= 2 and k and r) ans = min(ans, dp[last][j - 2][k - 1][l][dm][r]);

                                ans = min(ans, dp[last][a - 1][b - 1][a - 1][b - 1][0] + 2);
                                ans = min(ans, dp[last][2 * a - 2][b - 1][a][b - 1][1] + 3);
                                ans = min(ans, dp[last][2 * a - 2][b - 1][l][dm][1] + 2);
                            }

                            if(v[i] ^ v2[i]) {
                                if(j and k) 
                                    ans = min(ans, dp[last][j - 1][k - 1][l][dm][r]);

                                if(l and m) 
                                    ans = min(ans, dp[last][j][dk][l - 1][m - 1][r]);

                                ans = min(ans, dp[last][a - 1][b - 1][l][dm][0] + 1);
                                ans = min(ans, dp[last][j][dk][a - 1][b - 1][r] + 1);
                            }

                            if(!v[i] and !v2[i]) ans = min(ans, dp[last][l][dk][l][dm][r]);
                            
                        }
                    }
                }
            }
        }
        last = cur;
    }

    cout << dp[last][0][0][0][0][0] << "\n";

    return 0;
}
