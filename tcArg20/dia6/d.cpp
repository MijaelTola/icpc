#include <bits/stdc++.h>

using namespace std;

int n,m;
int dp[300010];
int cur[300010];
vector<pair<int,int> > e[100010];

int main() {
    
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    
    int lim = 0;

    for (int i = 0; i < m; ++i) {
        int x,y,w;
        cin >> x >> y >> w;
        lim = max(lim, w);
        e[w].push_back({x,y});
    }


    for (int i = 1; i <= lim; ++i) {
        for (auto x: e[i]) 
            cur[x.second] = 0;

        for (auto p: e[i]) 
            cur[p.second] = max(cur[p.second], dp[p.first] + 1);

        for (auto p: e[i])
            dp[p.second] = max(dp[p.second], cur[p.second]);
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i)
        ans = max(ans, dp[i]);
    cout << ans << "\n";

    return 0;
}

