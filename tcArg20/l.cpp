#include <bits/stdc++.h>

using namespace std;

int n;
int dp[310][310][310];
int m[310][310];

int main() {

    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> m[i][j];


    for (int k = n - 1; k >= 0; k--) {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int &ans = dp[i][j][k];
                if(j == n - 1 and j == n - 1) {
                    ans = m[i][j];
                    continue;
                }
                
                int x = i, y = k - i;
                int a = j, b = k - j;

                if(i + 1 < n and j + 1 < n)
                    ans = max(ans, dp[k + 1][i + 1][j + 1] + m[x][y] + m[a][b] - (i == j ? m[a][b] : 0));
            }
        }
    }
    return 0;
}

