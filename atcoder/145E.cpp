#include <bits/stdc++.h>

using namespace std;

int n,t,x,y;
int dp[3010][3010][2];
vector<pair<int,int> > v;


int main() {
    scanf("%d %d", &n, &t);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        v.emplace_back(x,y);
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= t; ++j) {
            for (int k = 0; k < 2; ++k) {
                if(k) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j][0] + v[i].second);
                    if(j - v[i].first >= 0) 
                        dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j - v[i].first][k] + v[i].second);
                } else {
                    if(j - v[i].first > 0)
                        dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j - v[i].first][k] + v[i].second);
                }
                dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j][k]);
            }
        }
    }
    
    printf("%d\n", dp[0][t][1]);
    return 0;
}

