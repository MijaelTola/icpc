#include <bits/stdc++.h>

using namespace std;

int n,q;
int dp[2][5020][3];

int main() {
    
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 5020; ++j)
            for (int k = 0; k < 3; ++k)
                dp[i][j][k] = -1e9;

    scanf("%d %d", &n, &q);

    
    vector<pair<int,int> > e;

    for (int i = 0; i < q; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        e.emplace_back(x,y);
    }
    
    sort(e.begin(), e.end());
    
    int last = 0;

    for (int i = 0; i < 5020; ++i)
        dp[last][i][0] = 0;

    for (int i = q - 1; i >= 0; i--) {
        int cur = 1 - last;

        for (int i = 0; i < 5020; ++i)
            dp[cur][i][0] = -1e9;
        
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k < 3; ++k) {
                int l = e[i].first;
                int r = e[i].second;
                if(j >= r) {
                    dp[cur][j][k] = max(dp[cur][j][k], dp[last][j][k]);   
                    if(k) dp[cur][j][k] = max(dp[cur][j][k], dp[last][j][k - 1]);
                    continue;
                }
                
                int maxi = max(j + 1, l);
                int cost = max(0, r - maxi + 1);

                if(k) dp[cur][j][k] = max(dp[cur][j][k], dp[last][j][k - 1]);
                dp[cur][j][k] = max(dp[cur][j][k], dp[last][r][k] + cost);
            }
        }
        last = cur;
    }

    printf("%d\n", dp[last][0][2]);
    return 0;
}

