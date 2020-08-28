#include <bits/stdc++.h>

using namespace std;

int n;
int m[18][18];
long long dp[1 << 17];

int main() {
    
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j)
            scanf("%d", &m[i][j]);

    long long ans = -1e17;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> v;
        for (int j = 0; j < n; ++j)
            if(i & (1 << j)) v.push_back(j);
        
        for (int j = 0; j < (int)v.size(); ++j)
            for (int k = j + 1; k < (int)v.size(); ++k)
                dp[i] += m[v[j]][v[k]];
        
        int mask = i;

        while(mask) {
            int cur = mask ^ i;
            dp[i] = max(dp[i], dp[mask] + dp[cur]);
            ans = max(ans, dp[i]);
            mask = (mask - 1) & i;
        }
    }

    printf("%lld\n", ans);
    return 0;
}

